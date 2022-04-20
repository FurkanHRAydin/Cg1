#include "Functions.h"
#include <iostream>
#

int Functions::id{0};

int Functions::getId() {
    id++;
    return id;
}

std::vector<glm::vec3> Functions::LaneRiesenfeld(std::vector<glm::vec3> vec_old, int n) {

     std::vector<glm::vec3> vec_neu;
     for (unsigned int i = 0; i < vec_old.size(); i++) {
         vec_neu.push_back(vec_old.at(i));
    }

    int size = vec_old.size();
    // Liste vergrosseren
    for (unsigned int i = 0; i < size; i++)
    {
        vec_neu.push_back(glm::vec3(0.0, 0.0, 0.0));
    }

    // Werte duplizieren und verschieben
    for (unsigned int i = 0; i < vec_neu.size(); i += 2)
    {
        vec_neu.at(vec_neu.size()-i-1) = vec_neu.at(size-1-(i/2));
        vec_neu.at(vec_neu.size()-i-2) = vec_neu.at(size-1-(i/2));
    }
    for (int j = 0; j < n; j++)
    {
        // mitteln
        for (unsigned int i = 0; i < vec_neu.size() - 1; i++)
        {
            vec_neu.at(i) = (vec_neu.at(i) + vec_neu.at(i+1)) / 2.0f;
        }
        // letztes Element löschen
        vec_neu.erase(vec_neu.begin()+vec_neu.size()-1);
    }
    return vec_neu;
}
