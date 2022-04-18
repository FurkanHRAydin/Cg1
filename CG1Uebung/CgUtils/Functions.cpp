#include "Functions.h"
#include <iostream>
#

int Functions::id{0};

int Functions::getId() {
    id++;
    return id;
}
/* mein Algo funktioniert warum auch immer nicht, arbeite mit detis weiter
std::vector<glm::vec3> Functions::LaneRiesenfeld(std::vector<glm::vec3> vec_alt, int n) {

    std::vector<glm::vec3> vec_neu;

    //Listen elemente einfuegen
    for(unsigned int i=0; i<vec_alt.size(); i++) {
        vec_neu.push_back(vec_alt.at(i));
    }

    int size = vec_alt.size();

    //Liste verdoppeln
    for(int i=0; i<size; i++) {
        vec_neu.push_back(glm::vec3(0.0,0.0,0.0));
    }

    //Elemente verdoppeln und schieben
    for(unsigned int i=0; i<vec_neu.size(); i+=2) {
        vec_neu.at(vec_neu.size()-i-1) = vec_neu.at(size-1-(i/2));
        vec_neu.at(vec_neu.size()-i-2) = vec_neu.at(size-1-(i/2));
    }

    //Mitteln
    for(int i=0; i<n; i++) {

        if (size + 1 >= (int) vec_neu.size()) {
            std::cout << "Ursprungslistegröße: " << size << ", Neue Liste Größe: " << vec_neu.size()
                      << "\t Neue Liste Größe sollte nicht kleiner gleich Ursprungsliste sein, deshalb wird abgebrochen" << std::endl;
            break;
        }

        for(unsigned int j=0; j<vec_neu.size()-1; j++) { //-1 weil sonst out of boundary
            vec_neu.at(i) = (vec_neu.at(i) + vec_neu.at(i+1)) / 2.0f;
        }
        vec_neu.erase(vec_neu.begin() + vec_neu.size()-1);
    }

    return vec_neu;
}
*/

std::vector<glm::vec3> Functions::LaneRiesenfeld(std::vector<glm::vec3> verticesold, int n) {
    // Unter 3 macht der Algorithmus keinen Sinn
    if(verticesold.size() < 3 || n == 0) return verticesold;

     std::vector<glm::vec3> vertices;
     for (unsigned int i = 0; i < verticesold.size(); ++i) {
         vertices.push_back(glm::vec3(verticesold.at(i)[0], verticesold.at(i)[1], verticesold.at(i)[2]));
    }

    int size = vertices.size();
    // Liste verdoppeln
    for (unsigned int i = 0; i < size; ++i)
    {
        vertices.push_back(glm::vec3(0.0, 0.0, 0.0));
    }

    // Werte duplizieren und verschieben
    for (unsigned int i = 0; i < vertices.size(); i += 2)
    {
        vertices.at(vertices.size()-i-1) = vertices.at(size-1-(i/2));
        vertices.at(vertices.size()-i-2) = vertices.at(size-1-(i/2));
    }

    //2-4 Schritte sind ueblich!
    for (int j = 0; j < n; ++j)
    {
        // Beim Mitteln darf Liste nicht kleiner sein als Ursprungsliste
        if (size + 1 >= (int) vertices.size()) {
            std::cout << "Ursprungslistegröße: " << size << ", Neue Liste Größe: " << vertices.size()
                      << "\t Neue Liste Größe sollte nicht kleiner gleich Ursprungsliste sein, deshalb wird abgebrochen" << std::endl;
            break;
        }

        // mitteln
        for (unsigned int i = 0; i < vertices.size() - 1; ++i)
        {
            vertices.at(i) = (vertices.at(i) + vertices.at(i+1)) / 2.0f;
        }
        // letztes Element löschen
        vertices.erase(vertices.begin()+vertices.size()-1);
    }
    return vertices;
}
