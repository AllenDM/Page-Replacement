 //
//  belady.cpp
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


void belady(list<int> &list, deque<int> &deque, int streamCount, int refStream[], int frameCount){
    bool isInQueue = false;
    int replacementVal;
    int pageFaultCount = 0;
    int displacementVal=0;
    int displacement[frameCount];
    int maxDisplacement = 0;
    
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
            if(deque[frameCount-1] != -1){
                   
                for(int k = 0; k < frameCount; k++)
                {
                    int targetValue = deque[k];
                  //  cout << "Target value  = " << targetValue << endl;
                    displacementVal = 0;
                    displacement[k] = 0;
                    for( int r = s+1; r < streamCount; r++)
                    {
                        
                       if (targetValue == refStream[r]){
                           displacementVal++;
                           displacement[k] = displacementVal;
                           
                          break;  
                         }
                        
                        displacementVal++;
                        
                        
                    }
               //       cout << "displacementVal is " << displacementVal << endl; 
                    if (displacementVal == streamCount - (s+1) ){
                        
                        displacement[k] = displacementVal;
                    }
                        
              //     cout << "displacement of " << deque[k] << " is " << displacement[k] << endl; 
                            
                }
                
                
                
                 maxDisplacement = 0;
                    for (int t = 0; t < frameCount; t++){
                        
                        if (displacement[t] > maxDisplacement){
              //              cout << "displacement"<< t << " is " << displacement[t] << " and deque" << t << " is " << deque[t] << endl;
                            maxDisplacement = displacement[t];
                            replacementVal = deque[t];
                            
                        }
                        
                        else if (maxDisplacement == 0){
                    
                           replacementVal = deque[t];
                        }
                        
                        
                    }
                
               
        //        cout << "Max Displacement is " << maxDisplacement << endl;
         //       cout << "replacementVal " << "=" << replacementVal;
                
                for (int i = 0; i < frameCount; i++){
                    if (deque[i] == replacementVal){
                        deque[i] = refStream[s];
                    }
                
                }
                pageFaultCount++;
                
            }
            
            else {
               
                
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
    cout << "Belady's algorithm incurred " << pageFaultCount << " page faults for this reference stream." << endl;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int streamCount;
    int frameCount;
    int refNumber;
    
    deque<int> framePosition;
    list<int> frameInfo;
   
    
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
    
    belady(frameInfo, framePosition, streamCount, refStream, frameCount);
 
    
    return 0;
}