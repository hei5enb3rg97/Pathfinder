=======================
TESTCASE 1 (EARTHQUAKE)
=======================

Grid size: 5x5
Ambulances at nodes: 0 12
Hospitals at nodes: 18 24
Houses at nodes: 6 15 20
Emergency triggered at houses: 6 15 20

Earthquake simulated, epicenter : node 10

Damaged nodes:
Intersection_7 (ID 7)
Intersection_8 (ID 8)
Intersection_11 (ID 11)
Intersection_12 (ID 12)
Intersection_13 (ID 13)
Intersection_14 (ID 14)
Intersection_17 (ID 17)
Intersection_19 (ID 19)
CityHospital (ID 24)

========
House 6:
========

Before:
Finding shortest path from ambulance to emergency house...
Path: AmbulanceStation -> Intersection_5 -> House_6
Distance: 13
Finding nearest hospital from the emergency house...
Path: House_6 -> Intersection_7 -> Intersection_12 -> Intersection_13 -> Hospital_18
Distance: 15

After:
Finding shortest path from ambulance to emergency house...
Path: AmbulanceStation -> Intersection_5 -> House_6
Distance: 13
Finding nearest hospital from the emergency house...
Path: House_6 -> Intersection_5 -> Intersection_10 -> House_15 -> Intersection_16 -> Intersection_21 -> Intersection_22 -> Intersection_23 -> Hospital_18
Distance: 48

=========
House 15:
=========

Before:
Finding shortest path from ambulance to emergency house...
Path: AmbulanceStation -> Intersection_5 -> Intersection_10 -> House_15
Distance: 20
Finding nearest hospital from the emergency house...
Path: House_15 -> Intersection_16 -> Intersection_17 -> Hospital_18
Distance: 17

After:
Finding shortest path from ambulance to emergency house...
Path: AmbulanceStation -> Intersection_5 -> Intersection_10 -> House_15
Distance: 20
Finding nearest hospital from the emergency house...
Path: House_15 -> Intersection_16 -> Intersection_21 -> Intersection_22 -> Intersection_23 -> Hospital_18
Distance: 33

=========
House 20:
=========

Before:
Finding shortest path from ambulance to emergency house...
Path: AmbulanceStation -> Intersection_5 -> Intersection_10 -> House_15 -> House_20
Distance: 26
Finding nearest hospital from the emergency house...
Path: House_20 -> House_15 -> Intersection_16 -> Intersection_17 -> Hospital_18
Distance: 23

After:
Finding shortest path from ambulance to emergency house...
Path: AmbulanceStation -> Intersection_5 -> Intersection_10 -> House_15 -> House_20
Distance: 26
Finding nearest hospital from the emergency house...
Path: House_20 -> Intersection_21 -> Intersection_22 -> Intersection_23 -> Hospital_18
Distance: 28


=================
TESTCASE 2 (RAIN)
=================

Grid size: 7x7
Ambulances at nodes: 0 10 20
Hospitals at nodes: 48 35
Houses at nodes: 7 14 21 28 30
Emergency triggered at houses: 7 14 28

Simulating rain

Flooded nodes:
Intersection_5 (ID 5)
Ambulance_10 (ID 10)
Intersection_12 (ID 12)
House_14 (ID 14)
Intersection_15 (ID 15)
Intersection_24 (ID 24)
Intersection_26 (ID 26)
Intersection_34 (ID 34)
Intersection_35 (ID 35)
Intersection_38 (ID 38)
Intersection_40 (ID 40)
Intersection_41 (ID 41)
Intersection_42 (ID 42)

========
House 7:
========

Before:
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7
Distance: 10
Finding nearest hospital from the emergency house...
Path: House_7 -> Intersection_8 -> Intersection_9 -> Intersection_16 -> Intersection_23 -> Intersection_24 -> Intersection_31 -> Intersection_32 -> Intersection_33 -> Intersection_40 -> Intersection_47 -> CityHospital
Distance: 41

After:
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7
Distance: 10
Finding nearest hospital from the emergency house...
Path: House_7 -> Intersection_8 -> Intersection_9 -> Intersection_16 -> Intersection_23 -> House_30 -> Intersection_31 -> Intersection_32 -> Intersection_39 -> Intersection_46 -> Intersection_47 -> CityHospital
Distance: 58


========
House 14:
========

Before:
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7 -> House_14
Distance: 16
Finding nearest hospital from the emergency house...
Path: House_14 -> Intersection_15 -> Intersection_22 -> Intersection_23 -> Intersection_24 -> Intersection_31 -> Intersection_32 -> Intersection_33 -> Intersection_40 -> Intersection_47 -> CityHospital
Distance: 40

After:
The node is flooded cannot access it

========
House 28:
========

Before:
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7 -> House_14 -> House_21 -> House_28
Distance: 25
Finding nearest hospital from the emergency house...
Path: House_28 -> Intersection_29 -> House_30 -> Intersection_31 -> Intersection_32 -> Intersection_33 -> Intersection_40 -> Intersection_47 -> CityHospital
Distance: 37

After:
Finding shortest path from ambulance to emergency house...
Path: Ambulance_20 -> Intersection_19 -> Intersection_18 -> Intersection_25 -> Intersection_32 -> Intersection_31 -> House_30 -> Intersection_29 -> House_28
Distance: 37
Finding nearest hospital from the emergency house...
Path: House_28 -> Intersection_29 -> Intersection_36 -> Intersection_43 -> Intersection_44 -> Intersection_45 -> Intersection_46 -> Intersection_47 -> CityHospital  
Distance: 43


========================
SAMPLE I/O (TEST CASE 2)
========================


==========================================
     EMERGENCY RESPONSE SIMULATION  
==========================================
Enter grid size (e.g., 5 for 5x5 grid): 7

 7x7 grid created successfully!
Each node ID ranges from 0 to 48.
Default: Node 0 = Ambulance | Node 48 = Hospital

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 1

Enter node ID to assign as Ambulance : 0
 Ambulance assigned to node 0

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 1

Enter node ID to assign as Ambulance : 10
 Ambulance assigned to node 10

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 1

Enter node ID to assign as Ambulance : 20
 Ambulance assigned to node 20

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 2

Enter node ID to assign as House : 7
 House assigned to node 7

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 2

Enter node ID to assign as House : 14
 House assigned to node 14

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 2

Enter node ID to assign as House : 21
 House assigned to node 21

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 2

Enter node ID to assign as House : 28
 House assigned to node 28

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 2

Enter node ID to assign as House : 30
 House assigned to node 30

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 4

Enter house node ID for emergency: 7

 Emergency triggered at node 7!
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7
Distance: 10
Finding nearest hospital from the emergency house...
Path: House_7 -> Intersection_8 -> Intersection_9 -> Intersection_16 -> Intersection_23 -> Intersection_24 -> Intersection_31 -> Intersection_32 -> Intersection_33 -> Intersection_40 -> Intersection_47 -> CityHospital
Distance: 41


=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 4

Enter house node ID for emergency: 14

 Emergency triggered at node 14!
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7 -> House_14
Distance: 16
Finding nearest hospital from the emergency house...
Path: House_14 -> Intersection_15 -> Intersection_22 -> Intersection_23 -> Intersection_24 -> Intersection_31 -> Intersection_32 -> Intersection_33 -> Intersection_40 -> Intersection_47 -> CityHospital
Distance: 40


=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 4

Enter house node ID for emergency: 28

 Emergency triggered at node 28!
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7 -> House_14 -> House_21 -> House_28
Distance: 25
Finding nearest hospital from the emergency house...
Path: House_28 -> Intersection_29 -> House_30 -> Intersection_31 -> Intersection_32 -> Intersection_33 -> Intersection_40 -> Intersection_47 -> CityHospital
Distance: 37


=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 6


 Simulating Rainfall and Drainage Failure...
Damaged nodes:
Intersection_5 (ID 5)
Ambulance_10 (ID 10)
Intersection_12 (ID 12)
House_14 (ID 14)
Intersection_15 (ID 15)
Intersection_24 (ID 24)
Intersection_26 (ID 26)
Intersection_34 (ID 34)
Intersection_35 (ID 35)
Intersection_38 (ID 38)
Intersection_40 (ID 40)
Intersection_41 (ID 41)
Intersection_42 (ID 42)


=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 4

Enter house node ID for emergency: 7

 Emergency triggered at node 7!
Finding shortest path from ambulance to emergency house...
Path: Ambulance_0 -> House_7
Distance: 10
Finding nearest hospital from the emergency house...
Path: House_7 -> Intersection_8 -> Intersection_9 -> Intersection_16 -> Intersection_23 -> House_30 -> Intersection_31 -> Intersection_32 -> Intersection_39 -> Intersection_46 -> Intersection_47 -> CityHospital
Distance: 58


=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 4

Enter house node ID for emergency: 14

 Emergency triggered at node 14!
The node is damaged cannot access it

=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 4

Enter house node ID for emergency: 28

 Emergency triggered at node 28!
Finding shortest path from ambulance to emergency house...
Path: Ambulance_20 -> Intersection_19 -> Intersection_18 -> Intersection_25 -> Intersection_32 -> Intersection_31 -> House_30 -> Intersection_29 -> House_28
Distance: 37
Finding nearest hospital from the emergency house...
Path: House_28 -> Intersection_29 -> Intersection_36 -> Intersection_43 -> Intersection_44 -> Intersection_45 -> Intersection_46 -> Intersection_47 -> CityHospital  
Distance: 43


=====================================
           MAIN MENU
=====================================
1. Add Ambulance
2. Add House
3. Add Hospital
4. Trigger Emergency at a House
5. Simulate Earthquake
6. Simulate Rain
7. Show Damaged Nodes
8. Exit Simulation
-------------------------------------
Enter your choice: 8


 Exiting Emergency Response Simulation. Stay safe!