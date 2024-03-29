// NetworkProject.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<iostream>
#include"NetworkObject.h"
#include"Packet.h"
#include"linkedList.h"
#include"stdlib.h"

int main()
{
	int counter = 0;

	double totalLostP = 0.00;
	int totalTravel = 0;
	int totalPackets = 0;
	int totalNodes = 0;

	while(counter < 1000){

		/*Creat Objects List*/
		int  numberOfNodes = rand() % 10 + 1;
		int  objectsCounter = 0;
		linkedList *list = new linkedList();

		/*Add objects into List*/
		for (int i = 0; i < numberOfNodes; i++) {

			/*get Id, put ID into object into List*/
			int objectId = i;
			NetworkObject *object = new NetworkObject(objectId);
			list->add_object(object);
			objectsCounter++;
		}

		NetworkObject* curr = list->head;
		vector<Packet*> randPackets;//Packets Array
		int sumTraveledPackets = 0;
		int sumLostedPackets = 0;
		int sumPackets = 0;

		/*Calculate packets traveled, packets were lost*/
		while (curr!= NULL) {
			/*Add packets into Packets Array*/
			for (int i = 0; i < curr->​maxPackets;i++) {
				randPackets.push_back(new Packet(0, 1, "Data"));//temperary targetID, sourceID,DATA
			}
			curr->addPackets(randPackets);
			curr->update();
			sumTraveledPackets += curr->TraveledPackets;
			sumLostedPackets += curr->DroppedPackets;
			sumPackets += curr->numOfPackets;
			curr = curr->next;
		}

		/*Print num of Objects(Nodes) in the Linked list*/
		std::cout << "Situation:" << counter << std::endl;
		std::cout << numberOfNodes << " nodes in the linked list." << std::endl;
		std::cout << sumTraveledPackets << " packets traveled through the system." << std::endl;
		std::cout << ((double)sumLostedPackets/(double)sumPackets)*100.00 << "% packets losted." << std::endl;

		totalLostP += (double)sumLostedPackets / (double)sumPackets;
		totalTravel += sumTraveledPackets;
		counter++;
	}

	
	std::cout << "Conclusion" << std::endl;
	std::cout << "Average percentage of packets lost: " << (totalLostP/1000.00)*100.00 <<"%"<<std::endl;
	std::cout << "Average travel time of a packet: " << totalTravel/1000 << std::endl;

	system("pause");
	return 0;
}