#include <SFML/Graphics.hpp>
#include "dataBase.h"

using namespace std;
using namespace sf;

const int WIDTH = 1600;
const int HEIGHT = 900;

int indexObject = -1;
string state = "typeUser";
DotaDex dotaDex;
string playerUsername = "";

Event event;
RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML Example"); // Create a window

Font gameFont;
Text upTitle;
Text usernameLabel;
Text usernameInput;
Text menuOption[5];

pair<Texture, Sprite> dota2Map;
pair<Texture, Sprite> backgrounds[2];

vector<Heroe*> heroes;
vector< pair<Texture, Sprite> > heroesImages;

vector<Dota2Item*> items;
vector< pair<Texture, Sprite> > itemsImages;

vector<Runa*> runes;
vector< pair<Texture, Sprite> > runesImages;

RectangleShape focusRect;
Text focusDescription;


// Aux Functions

float getWidth(Text &txt){
    return txt.getLocalBounds().width;
}

float getHeight(Text &txt){
    return txt.getLocalBounds().height;
}

string fixName(string heroName){ // Parse hero Name to .png name
    // Replace spaces with underscores
    for (char &c : heroName) {
        if (c == ' ') c = '_';
        else  c = tolower(c); // Convert upper case to lower case
    }
    return heroName;
}

bool isMouseInRectangle(const Vector2i& mousePosition, const RectangleShape& rectangle) {
    FloatRect rectBounds = rectangle.getGlobalBounds();
    return rectBounds.contains(static_cast<Vector2f>(mousePosition));
}

int loadSfmlItems(){

    // Load Fonts
    gameFont.loadFromFile("fonts/Audiowide-Regular.ttf");

    // Create Text Objects
    usernameLabel = Text("Type your Username", gameFont, 50);
    usernameLabel.setPosition(((float) WIDTH/2) - getWidth(usernameLabel)/2.0f , (float) HEIGHT / 6);

    menuOption[0] = Text("1 - Heroes", gameFont, 50);
    menuOption[0].setPosition(((float) WIDTH*4/7) , (float) HEIGHT / 4);

    menuOption[1] = Text("2 - Runas", gameFont, 50);
    menuOption[1].setPosition(((float) WIDTH*4/7) , (float) HEIGHT / 4 + 100);

    menuOption[2] = Text("3 - Items", gameFont, 50);
    menuOption[2].setPosition(((float) WIDTH*4/7) , (float) HEIGHT / 4 + 200);

    menuOption[3] = Text("4 - Mapa", gameFont, 50);
    menuOption[3].setPosition(((float) WIDTH*4/7) , (float) HEIGHT / 4 + 300);

    menuOption[4] = Text("5 - Salir", gameFont, 50);
    menuOption[4].setPosition(((float) WIDTH*4/7) , (float) HEIGHT / 4 + 400);

    upTitle = Text("HEROES", gameFont, 50);
    upTitle.setPosition(((float) WIDTH/2) - getWidth(upTitle)/2.0f , (float) HEIGHT / 50);

    usernameInput = Text("", gameFont, 38);

    // Load map image

    if (!dota2Map.first.loadFromFile("images/dota2Map.jpg")) {
        cerr << "Error loading background1 image!" << endl;
        return 1;
    }
    dota2Map.second = Sprite(dota2Map.first);
    
    // Resize
    float targetHeight = (float) HEIGHT / 1.25;
    float scaleFactor = (float) targetHeight / dota2Map.second.getLocalBounds().height;
    dota2Map.second.setScale(scaleFactor, scaleFactor);
    dota2Map.second.setPosition(((float) WIDTH / 2.0) - (dota2Map.second.getGlobalBounds().width  / 2.0), 
                                ((float) HEIGHT/ 2.0) - (dota2Map.second.getGlobalBounds().height / 2.0));

    // Load background image
    for (int i = 0; i < 2; ++i){
        if (!backgrounds[i].first.loadFromFile("images/background" + to_string(i+1) +".jpg")) {
            cerr << "Error loading background1 image!" << endl;
            return 1;
        }
        backgrounds[i].second = Sprite(backgrounds[i].first);
    }


    // HEROES IMAGES ------------------------------------------------------------------------------
    string heroName;
    heroesImages.assign(heroes.size(), { Texture(), Sprite() });

    cout << "Heroes Number: " << heroes.size() <<  endl;
    for (int i = 0; i < heroes.size(); ++i){
        heroName = fixName((heroes[i])->obtenerNombre()) + ".png";
        cout << "Hero Image Name: " << heroName << endl;
        if (!heroesImages[i].first.loadFromFile("images/heroesImages/" + heroName)) {
            cerr << "Error loading hero image!" << endl;
            return 1;
        }
        heroesImages[i].second = Sprite(heroesImages[i].first);
    }

    // Resize Calculations:

    int startHeigh = HEIGHT / 10;
    int imagesPerRow = 5;
    float padding = 15;
    float x, y, w, h;
    
    float targetWidth = (WIDTH / imagesPerRow) - padding - (padding / imagesPerRow);
    scaleFactor = (float) targetWidth / heroesImages[0].second.getLocalBounds().width;
    
    for (int j = 0; j < imagesPerRow; ++j){ // X
        for (int i = 0; i*imagesPerRow + j < heroesImages.size(); ++i){ // Y

            heroesImages[i*imagesPerRow + j].second.setScale(scaleFactor, scaleFactor);

            w = heroesImages[i*imagesPerRow + j].second.getGlobalBounds().width;
            h = heroesImages[i*imagesPerRow + j].second.getGlobalBounds().height;

            x = padding*((float) j+1) + w*j;
            y = startHeigh + padding*((float) i) + h * i;

            heroesImages[i*imagesPerRow + j].second.setPosition(x, y);

        }
    }

    // ITEMS IMAGES ------------------------------------------------------------------------------
    string itemName;
    itemsImages.assign(items.size(), { Texture(), Sprite() });

    cout << "Items Number: " << items.size() <<  endl;
    for (int i = 0; i < items.size(); ++i){
        itemName = items[i]->obtenerNombre() + ".png";
        cout << "Item Image Name: " << itemName << endl;
        if (!itemsImages[i].first.loadFromFile("images/itemsImages/" + itemName)) {
            cerr << "Error loading hero image!" << endl;
            return 1;
        }
        itemsImages[i].second = Sprite(itemsImages[i].first);
    }

    // Resize Calculations:

    startHeigh = HEIGHT / 10;
    imagesPerRow = 8;
    padding = 15;
    x, y, w, h;
    
    targetWidth = (WIDTH / imagesPerRow) - padding - (padding / imagesPerRow);
    scaleFactor = (float) targetWidth / itemsImages[0].second.getLocalBounds().width;
    
    for (int j = 0; j < imagesPerRow; ++j){ // X
        for (int i = 0; i*imagesPerRow + j < itemsImages.size(); ++i){ // Y

            itemsImages[i*imagesPerRow + j].second.setScale(scaleFactor, scaleFactor);

            w = itemsImages[i*imagesPerRow + j].second.getGlobalBounds().width;
            h = itemsImages[i*imagesPerRow + j].second.getGlobalBounds().height;

            x = padding*((float) j+1) + w*j;
            y = startHeigh + padding*((float) i) + h * i;

            itemsImages[i*imagesPerRow + j].second.setPosition(x, y);

        }
    }

    // RUNES IMAGES ------------------------------------------------------------------------------
    string runeName;
    runesImages.assign(runes.size(), { Texture(), Sprite() });

    cout << "Runes Number: " << runes.size() <<  endl;
    for (int i = 0; i < runes.size(); ++i){
        runeName = runes[i]->getNombre() + ".png";
        cout << "Rune Image Name: " << runeName << endl;
        if (!runesImages[i].first.loadFromFile("images/runesImages/" + runeName)) {
            cerr << "Error loading hero image!" << endl;
            return 1;
        }
        runesImages[i].second = Sprite(runesImages[i].first);
    }

    // Resize Calculations:

    startHeigh = HEIGHT / 10;
    imagesPerRow = 6;
    padding = 15;
    x, y, w, h;
    
    targetWidth = (WIDTH / imagesPerRow) - padding - (padding / imagesPerRow);
    scaleFactor = (float) targetWidth / runesImages[0].second.getLocalBounds().width;
    
    for (int j = 0; j < imagesPerRow; ++j){ // X
        for (int i = 0; i*imagesPerRow + j < runesImages.size(); ++i){ // Y

            runesImages[i*imagesPerRow + j].second.setScale(scaleFactor, scaleFactor);

            w = runesImages[i*imagesPerRow + j].second.getGlobalBounds().width;
            h = runesImages[i*imagesPerRow + j].second.getGlobalBounds().height;

            x = padding*((float) j+1) + w*j;
            y = startHeigh + padding*((float) i) + h * i;

            runesImages[i*imagesPerRow + j].second.setPosition(x, y);

        }
    }

    // Focus Rect ------------------------------------------------------------------------------

    focusRect = RectangleShape(Vector2f(WIDTH / 1.15, HEIGHT / 1.15)); // width, height
    focusRect.setFillColor(Color(100, 100, 100)); // Gray color
    focusRect.setPosition((WIDTH / 2) - (focusRect.getGlobalBounds().width  / 2), 
                              (HEIGHT/ 2) - (focusRect.getGlobalBounds().height / 2));

    return 0;

}

bool inputTextKeyboardEvent(Text &textObject, string &strVar){

    char typedChar = static_cast<char>(event.text.unicode);

    if (typedChar == '\b') { // Backspace
        if (!strVar.empty())  strVar.pop_back();
    } 
    else if (typedChar == '\r') cout << "Entered Text: " << strVar << endl; // Enter
    else strVar += typedChar;

    textObject.setString(strVar); // Update textObject

    return typedChar == '\r'; // return true if enter pressed

}

void setSubHeroDescrition(int index){

    string description = "";

    indexObject = index;
    
    description += "INFORMACION BASICA:";
    description += "\nNombre del Heroe: " +  heroes[index]->obtenerNombre() ;
    description += "\nTipo del Heroe: " + heroes[index]->obtenerTipo();

    string newBio = "\n";
    string bio = heroes[index]->obtenerBiografia();
    replace(bio.begin(), bio.end(), '\n', ' ');

    int counter = 0;    
    for (int i = 0; i < bio.size(); ++i, ++counter){
        if (counter > 40 && bio[i] == ' '){
            newBio += '\n';
            counter = 0;
        }
        else newBio += bio[i];
    }
    cout << "New Bio: " << newBio;
    description += "\nBiografia del Heroe: " + newBio;

    Estadisticas estadisticas = heroes[index]->obtenerEstadisticas();
    description += "\n\nESTADISTICAS DEL HEROE:";
    description += "\n - Fuerza: " + to_string(estadisticas.fuerza);
    description += "\n - Agilidad: " + to_string(estadisticas.agilidad);
    description += "\n - Inteligencia: " + to_string(estadisticas.inteligencia);

    vector<string> habilidades = heroes[index]->obtenerHabilidades();
    description += "\n\nHABILIDADES DEL HEROE:";
    for (const string& habilidad : habilidades)  description += "\n - " + habilidad;

    focusDescription = Text(description, gameFont, 28);
    focusDescription.setPosition(focusRect.getPosition().x + 20, focusRect.getPosition().y + 30);

}

void setSubItemDescrition(int index){
    string description = "";

    indexObject = index;

    description += "INFORMACION:";
    description += "\nNombre del Item: " +  items[index]->obtenerNombre();
    description += "\nCosto del Item: " + to_string(items[index]->obtenerCosto());

    string newBio = "\n";
    string bio = items[index]->obtenerDescripcion();
    replace(bio.begin(), bio.end(), '\n', ' ');

    int counter = 0;    
    for (int i = 0; i < bio.size(); ++i, ++counter){
        if (counter > 30 && bio[i] == ' '){
            newBio += '\n';
            counter = 0;
        }
        else newBio += bio[i];
    }
    description += "\n\nDescripcion del Item: " + newBio;

    cout << "Full Description:" << endl;
    cout << description << endl;

    focusDescription = Text(description, gameFont, 40);
    focusDescription.setPosition(focusRect.getPosition().x + 20, focusRect.getPosition().y + 30);

}


void setSubRuneDescrition(int index){
    string description = "";

    indexObject = index;

    description += "INFORMACION:";
    description += "\nNombre de la Runa: " +  runes[index]->getNombre();
    description += "\nTipo de Runa: " + runes[index]->getTipo();

    cout << "Full Description:" << endl;
    cout << description << endl;

    focusDescription = Text(description, gameFont, 50);
    focusDescription.setPosition(focusRect.getPosition().x + 20, focusRect.getPosition().y + 30);

}


string login(string &nameText){

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) window.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();
        else if (event.type == Event::TextEntered && event.text.unicode < 128){
            if (inputTextKeyboardEvent(usernameInput, nameText)){ // Enter
                dotaDex = DotaDex(nameText);
                state = "menu";
                upTitle = Text("Welcome " + nameText + "!", gameFont, 50);
                upTitle.setPosition(((float) WIDTH/2) - getWidth(upTitle)/2.0f , (float) HEIGHT / 50);
                // nameText.clear();
            }
        }
    }

    usernameInput = Text(nameText, gameFont, 50);
    usernameInput.setPosition(((float) WIDTH/2) - getWidth(usernameInput)/2.0f , (float) HEIGHT/4);

    // Draw area
    window.draw(backgrounds[0].second);
    window.draw(usernameLabel);
    window.draw(usernameInput);

    return state;
}

string mainMenu(){

    upTitle = Text("Welcome " + playerUsername + "!", gameFont, 50);
    upTitle.setPosition(((float) WIDTH/2) - getWidth(upTitle)/2.0f , (float) HEIGHT / 50);

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) window.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();
        else if (event.type == Event::TextEntered) {
            if (event.text.unicode == 8 || event.text.unicode == 127){
                state = "typeUser";
                playerUsername = "";
            }
            else if (event.text.unicode == '1'){
                state = "heroes";
                upTitle = Text("HEROES", gameFont, 50);
                upTitle.setPosition(((float) WIDTH/2) - getWidth(upTitle)/2.0f , (float) HEIGHT / 50);
            }
            else if (event.text.unicode == '2'){
                state = "runas";
                upTitle = Text("RUNAS", gameFont, 50);
                upTitle.setPosition(((float) WIDTH/2) - getWidth(upTitle)/2.0f , (float) HEIGHT / 50);
            }
            else if (event.text.unicode == '3'){
                state = "items";
                upTitle = Text("ITEMS", gameFont, 50);
                upTitle.setPosition(((float) WIDTH/2) - getWidth(upTitle)/2.0f , (float) HEIGHT / 50);
            }
            else if (event.text.unicode == '4'){
                state = "mapas";
                upTitle = Text("MAPAS", gameFont, 50);
                upTitle.setPosition(((float) WIDTH/2) - getWidth(upTitle)/2.0f , (float) HEIGHT / 50);
            }
            
            else if (event.text.unicode == '5'){
                state = "salir";
            }
        }

    }

    // Draw area
    window.draw(backgrounds[1].second);
    window.draw(upTitle);

    for (int i = 0; i < 5; ++i) window.draw(menuOption[i]); 

    return state;

}

void subHero(){

    window.draw(focusRect);

    pair <float, float> pastPosition = { heroesImages[indexObject].second.getPosition().x,
                                         heroesImages[indexObject].second.getPosition().y };

    heroesImages[indexObject].second.setPosition(
        Vector2f(focusRect.getPosition().x + focusRect.getGlobalBounds().width 
                 -heroesImages[indexObject].second.getGlobalBounds().width - 30, 
                 focusRect.getPosition().y + 30)
    );

    window.draw(heroesImages[indexObject].second);
    window.draw(focusDescription);

    heroesImages[indexObject].second.setPosition(Vector2f(pastPosition.first, pastPosition.second));

}

void subItem(){

    window.draw(focusRect);

    pair <float, float> pastPosition = { itemsImages[indexObject].second.getPosition().x,
                                         itemsImages[indexObject].second.getPosition().y };

    itemsImages[indexObject].second.setPosition(
        Vector2f(focusRect.getPosition().x + focusRect.getGlobalBounds().width 
                 -itemsImages[indexObject].second.getGlobalBounds().width - 30, 
                 focusRect.getPosition().y + 30)
    );

    window.draw(itemsImages[indexObject].second);
    window.draw(focusDescription);

    itemsImages[indexObject].second.setPosition(Vector2f(pastPosition.first, pastPosition.second));

}

void subRune(){

    window.draw(focusRect);

    pair <float, float> pastPosition = { runesImages[indexObject].second.getPosition().x,
                                         runesImages[indexObject].second.getPosition().y };

    runesImages[indexObject].second.setPosition(
        Vector2f(focusRect.getPosition().x + focusRect.getGlobalBounds().width 
                 -runesImages[indexObject].second.getGlobalBounds().width - 30, 
                 focusRect.getPosition().y + 30)
    );

    window.draw(runesImages[indexObject].second);
    window.draw(focusDescription);

    runesImages[indexObject].second.setPosition(Vector2f(pastPosition.first, pastPosition.second));

}

string heroesMenu(){

    RectangleShape rectangleButton(Vector2f(heroesImages[0].second.getGlobalBounds().width, 
                                      heroesImages[0].second.getGlobalBounds().height));

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) window.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();
        else if (event.type == Event::TextEntered){
            if (event.text.unicode == 8 || event.text.unicode == 127){
                if (indexObject == -1) state = "menu";
                else indexObject = -1;
            }
        }
        else if (indexObject == -1 && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            for (int i = 0; i < heroesImages.size(); ++i){
                rectangleButton.setPosition(heroesImages[i].second.getPosition().x, heroesImages[i].second.getPosition().y);
                if (isMouseInRectangle(Mouse::getPosition(window), rectangleButton)) {
                    setSubHeroDescrition(i);
                    break;
                }
            }
        }

    }

    // Draw Area
    window.draw(backgrounds[1].second);
    window.draw(upTitle);

    // Draw Heroes
    for (int i = 0; i < heroesImages.size(); ++i) window.draw(heroesImages[i].second);
    
    if (indexObject != -1) subHero();

    return state;
}

string itemsMenu(){

    RectangleShape rectangleButton(Vector2f(itemsImages[0].second.getGlobalBounds().width, 
                                      itemsImages[0].second.getGlobalBounds().height));

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) window.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();
        else if (event.type == Event::TextEntered){
            if (event.text.unicode == 8 || event.text.unicode == 127){
                if (indexObject == -1) state = "menu";
                else indexObject = -1;
            }
        }
        else if (indexObject == -1 && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            for (int i = 0; i < itemsImages.size(); ++i){
                rectangleButton.setPosition(itemsImages[i].second.getPosition().x, itemsImages[i].second.getPosition().y);
                if (isMouseInRectangle(Mouse::getPosition(window), rectangleButton)) {
                    setSubItemDescrition(i);
                    break;
                }
            }
        }

    }

    // Draw Area
    window.draw(backgrounds[1].second);
    window.draw(upTitle);

    // Draw Items
    for (int i = 0; i < itemsImages.size(); ++i) window.draw(itemsImages[i].second);
    
    if (indexObject != -1) subItem();

    return state;

}

string mapsMenu(){

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) window.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();
        else if (event.type == Event::TextEntered){
            if (event.text.unicode == 8 || event.text.unicode == 127){
                if (indexObject == -1) state = "menu";
                else indexObject = -1;
            }
        }

    }

    // Draw Area
    window.draw(backgrounds[1].second);
    window.draw(upTitle);
    window.draw(dota2Map.second);


    return state;

}

string runasMenu(){

    RectangleShape rectangleButton(Vector2f(runesImages[0].second.getGlobalBounds().width, 
                                      runesImages[0].second.getGlobalBounds().height));

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) window.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();
        else if (event.type == Event::TextEntered){
            if (event.text.unicode == 8 || event.text.unicode == 127){
                if (indexObject == -1) state = "menu";
                else indexObject = -1;
            }
        }
        else if (indexObject == -1 && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            for (int i = 0; i < runesImages.size(); ++i){
                rectangleButton.setPosition(runesImages[i].second.getPosition().x, runesImages[i].second.getPosition().y);
                if (isMouseInRectangle(Mouse::getPosition(window), rectangleButton)) {
                    setSubRuneDescrition(i);
                    break;
                }
            }
        }

    }

    // Draw Area
    window.draw(backgrounds[1].second);
    window.draw(upTitle);

    // Draw Runes
    for (int i = 0; i < runesImages.size(); ++i) window.draw(runesImages[i].second);

    if (indexObject != -1) subRune();

    return state;
}

int main() {

    crearHeroes(heroes); // Create Heroes
    crearItems(items); // Create Items
    crearRunas(runes); // Create Items
    
    loadSfmlItems(); // Load Text, fonts, images, etc
    
    while (window.isOpen()) { // Main loop
        
        window.clear(); // Clear the window

        if (state == "typeUser")    login(playerUsername);
        else if (state == "menu")   mainMenu();
        else if (state == "heroes") heroesMenu();
        else if (state == "runas")  runasMenu();
        else if (state == "items")  itemsMenu();
        else if (state == "mapas")  mapsMenu();
        else if (state == "salir")  window.close();
        else cout << "BAD STATE" << endl;

        window.display(); // Display the content of the window

    }

    liberarHeroes(heroes);
    liberarItems(items);

    return 0;
}
