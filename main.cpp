#include "GridGraph.h"
#include <iostream>
using namespace std;

int main() {
    // Interactive simulation menu
    cout << "==========================================\n";
    cout << "     EMERGENCY RESPONSE SIMULATION  \n";
    cout << "==========================================\n";

    int n;
    cout << "Enter grid size (e.g., 5 for 5x5 grid): ";
    cin >> n;
    if (n <= 1) {
        cout << " Invalid grid size. Using default 5x5.\n";
        n = 5; // default grid size
    }

    GridGraph g(n);
    g.buildGrid(); // calls the graph constructor

    cout << "\n " << n << "x" << n << " grid created successfully!\n";
    cout << "Each node ID ranges from 0 to " << (n * n - 1) << ".\n";
    cout << "Default: Node 0 = Ambulance | Node " << (n*n - 1) << " = Hospital\n";

    // Default starting setup
    g.assignNodeType(0, AMBULANCE, "AmbulanceStation");
    g.assignNodeType(n * n - 1, HOSPITAL, "CityHospital");

    bool running = true;
    while (running) {
        cout << "\n=====================================\n";
        cout << "           MAIN MENU\n";
        cout << "=====================================\n";
        cout << "1. Add Ambulance\n";
        cout << "2. Add House\n";
        cout << "3. Add Hospital\n";
        cout << "4. Trigger Emergency at a House\n";
        cout << "5. Simulate Earthquake\n";
        cout << "6. Simulate Rain\n";
        cout << "7. Show Damaged Nodes\n";
        cout << "8. Exit Simulation\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                // Add ambulance node
                int id;
                cout << "Enter node ID to assign as Ambulance : ";
                cin >> id;
                if (id >= 0 && id < n*n) {
                    g.assignNodeType(id, AMBULANCE, "Ambulance_" + to_string(id));
                    cout << " Ambulance assigned to node " << id << endl;
                } else cout << " Invalid node ID.\n";
                break;
            }

            case 2: {
                // Add house node
                int id;
                cout << "Enter node ID to assign as House : ";
                cin >> id;
                if (id >= 0 && id < n*n) {
                    g.assignNodeType(id, HOUSE, "House_" + to_string(id));
                    cout << " House assigned to node " << id << endl;
                } else cout << " Invalid node ID.\n";
                break;
            }

            case 3: {
                // Add hospital node
                int id;
                cout << "Enter node ID to assign as Hospital : ";
                cin >> id;
                if (id >= 0 && id < n*n) {
                    g.assignNodeType(id, HOSPITAL, "Hospital_" + to_string(id));
                    cout << " Hospital assigned to node " << id << endl;
                } else cout << " Invalid node ID.\n";
                break;
            }

            case 4: {
                // Trigger emergency at a house
                int houseID;
                cout << "Enter house node ID for emergency: ";
                cin >> houseID;
                if (houseID >= 0 && houseID < n*n) {
                    cout << "\n Emergency triggered at node " << houseID << "!\n";
                    g.emergency(houseID);
                } else cout << "Invalid node ID.\n";
                break;
            }

            case 5: {
                // Simulate earthquake
                int epicenter; // epicenter ID
                cout << "Enter earthquake epicenter node ID: ";
                cin >> epicenter;
                if (epicenter >= 0 && epicenter < n*n) {
                    cout << "\n Simulating Earthquake...\n";
                    g.simulateearthquake(epicenter);
                } else cout << "Invalid node ID.\n";
                break;
            }

            case 6: {
                // Simulate rain
                cout << "\n Simulating Rainfall and Drainage Failure...\n";
                g.simulateRain();
                break;
            }

            case 7: {
                // Show all damaged nodes
                g.damage();
                break;
            }

            case 8: {
                // Exit the simulation
                running = false;
                cout << "\n Exiting Emergency Response Simulation. Stay safe!\n";
                break;
            }

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}