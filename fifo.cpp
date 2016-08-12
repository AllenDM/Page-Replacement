//
//  fifo.cpp
//  COP3610project
//
//  Created by Allen Moody on 4/5/16.
//  Copyright © 2016 home. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <list>
using namespace std;


void fifo(deque<int> &deque, queue<int> &queue, int streamCount, int refStream[], int frameCount){
    bool isInQueue = false;
    int replacementVal;
    int pageFaultCount = 0;
    
    for (int z = 0; z < frameCount; z++)
    {
        deque[z] = -1;  
    } // represents empty frame
    
    for (int s = 0; s< streamCount; s++){
        isInQueue = false;
    for (int u = 0; u < frameCount; u++){
        if (refStream[s] == deque[u] ){
            isInQueue = true;
            
         }
       
 
    } // end of frameCount loop
         if (isInQueue == false){
            // cout << queue.size();
            if(queue.size() == frameCount){
                
                replacementVal = queue.front();
                
                queue.pop();
                
                queue.push(refStream[s]);
                
                for (int i = 0; i < frameCount; i++){
                    if (deque[i] == replacementVal){
                        deque[i] = refStream[s];
                    }
                
                }
                pageFaultCount++;
                
            }
            
            else {
                queue.push(refStream[s]);
                
                deque.push_back(refStream[s]);
                pageFaultCount++;
            }
         }
        
        
        
        cout << endl;
        for (int r = 0; r < frameCount; r++){
            
            if (deque[r] == refStream[s] && isInQueue == false){
                cout << deque[r] << "*" << endl;
            } 
            else
            cout << deque[r] << endl;
        } // prints current pages in memory
        cout << endl;
            
    } // end of streamCount loop
    cout << "FIFO incurred " << pageFaultCount << " page faults for this reference stream." << endl;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int streamCount;
    int frameCount;
    int refNumber;
    
    deque<int> framePosition;
    queue<int> fifoFrameInfo;
   
    
   cout << "Enter frame count: ";
    cin >>  frameCount;
    cout << "Enter number of references: ";
    cin >> streamCount;
    int refStream[streamCount];
    for (int w = 0; w < streamCount; w++){
        
        cout << "Enter next number: ";
       cin >> refNumber;
        refStream[w] = refNumber;
    }
   cout << "The reference stream is: " << endl;
   for (int e = 0; e < streamCount; e++){
        
    cout << refStream[e] << " ";
   }
    cout << endl;
    
    fifo(framePosition, fifoFrameInfo, streamCount, refStream, frameCount );
 
    
    return 0;
}