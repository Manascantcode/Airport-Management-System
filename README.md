# ✈️ Airport Management System (C)

A modular, menu-driven Airport Management System written in C, demonstrating
the use of core data structures and clean software design.

## 🚀 Features
- Flight management using **Linked Lists**
- Passenger booking with **Hash Table (O(1) lookup)**
- Airport route visualization using **Graph (Adjacency Matrix)**
- Boarding & luggage charge calculation
- Modular code structure with header files

## 🧠 Data Structures Used
- Linked List
- Hash Table (Separate Chaining)
- Graph (Undirected)

## 🗂 Project Structure
```text
Airport-Management-System/
├── src/
│   ├── flight.c
│   ├── passenger.c
│   ├── graph.c
│   └── main.c
│
├── include/
│   ├── flight.h
│   ├── passenger.h
│   └── graph.h
│
├── README.md
└── .gitignore




## ▶️ How to Run
```bash
gcc src/*.c -Iinclude -o airport
./airport
 or (On Windows) - .\airport.exe
