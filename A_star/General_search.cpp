#include "implementation.cpp"

#include "implementation.cpp"

template<typename Graph>
void breath_first_search (Graph graph, typename Graph::Location start) {
    typedef typename Graph::Location Location;
    queue<Location> frontier;
    frontier.push(start);

    unordered_set<Location> visited;
    visited.insert(start);

    while (!frontier.empty()) {
        auto current = frontier.front();
        frontier.pop();

        std::out << "Visiting " << current << std::endl;
        for (auto & next : graph.neighbors(current)) {
            if(!visited.count(next)) {
                frontier.push(next);
                visited.insert(next);
            }
        }
    }
}

int main() {
    SquareGrid grid = make_diagram1();
    auto parents = breadth_first_search(grid, std::make_tuple(7,8));
    draw_grid(grid, 2, nullptr, &parents);
    return 0;
}
