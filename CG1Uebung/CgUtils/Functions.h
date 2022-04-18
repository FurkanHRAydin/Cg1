#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <glm/glm.hpp>
class Functions
{
public:
    Functions();
    static std::vector<glm::vec3> LaneRiesenfeld(std::vector<glm::vec3> vec_alt, int n);
    static int getId();

private:
    static int id;
};

#endif // FUNCTIONS_H
