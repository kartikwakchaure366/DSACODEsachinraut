# EV Charging Station Route Finder

## Problem Statement

Represent electric vehicle charging stations and connecting routes with non-negative distance weights, and apply Dijkstra's algorithm to find the shortest route from a vehicle's current location to a selected charging station.

## Language

C++

## Algorithm

Dijkstra's Shortest Path Algorithm

## Description

This project is a C++-based application that helps electric vehicle users find the shortest route to a selected charging station. It represents charging stations as vertices and connecting roads as weighted edges in a graph. Dijkstra's algorithm calculates the shortest distance from the vehicle's current location to the selected charging station and displays the complete route.

## Features

- Graph representation using an adjacency list.
- Non-negative distance weights.
- Shortest route calculation using Dijkstra's algorithm.
- Displays the minimum distance in kilometres.
- Displays the complete route from the starting point to the destination.

## Sample Output

```
EV CHARGING STATION ROUTE FINDER
--------------------------------
Starting point : Current Location
Destination    : Selected Station
Shortest route : Current Location -> Station B -> Station A -> Station C -> Selected Station
Minimum distance: 10 km
```

## How to Run

1. Copy the C++ code into a file named `ev_charging_dijkstra.cpp`.
2. Open the file in Dev-C++.
3. Compile and run the program.
4. View the shortest route and minimum distance in the output window.

## Author

Student DSA Assignment

## License

This project is intended for educational purposes.
