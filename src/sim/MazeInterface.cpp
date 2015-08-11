#include "MazeInterface.h"

#include "SimUtilities.h"

namespace sim {

MazeInterface::MazeInterface(std::vector<std::vector<BasicTile>>* basicMaze) : m_basicMaze(basicMaze) {
}

void MazeInterface::setWall(int x, int y, char direction, bool wallExists) {

    if (x < 0 || getWidth() <= x || y < 0 || getHeight() <= y) {
        SimUtilities::print(std::string("Error: The generated maze width and height values are "
        + std::to_string(getWidth()) + " and " + std::to_string(getHeight()) + ", respectively."
        + "There is no tile at position (") + std::to_string(x) + std::string(", ")
            + std::to_string(y) + std::string("), and thus you cannot set its wall value."));
        return;
    }

    if (!SimUtilities::mapContains(CHAR_TO_DIRECTION, direction)) {
        SimUtilities::print(std::string("Error: The character '") + direction
            + std::string("' is not mapped to a valid direction."));
        return;
    }
    m_basicMaze->at(x).at(y).walls.at(CHAR_TO_DIRECTION.at(direction)) = wallExists;
}

double MazeInterface::getRandom() {
    return SimUtilities::getRandom();
}

int MazeInterface::getWidth() {
    return m_basicMaze->size();
}

int MazeInterface::getHeight() {
    return (m_basicMaze->size() > 0 ? m_basicMaze->at(0).size() : 0);
}

} // namespace sim