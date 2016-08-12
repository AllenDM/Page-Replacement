
#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <list>
using namespace std;





void belady(list<int> &list, deque<int> &deque, int streamCount, std::deque<int> refStream, int frameCount){
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


void lru(list<int> &list, deque<int> &deque, int streamCount, std::deque<int> refStream, int frameCount){
    bool isInQueue = false;
    int replacementVal;
    int pageFaultCount = 0;
    int recentlyUsed;
    int leastRecentlyUsed;
    
   for (int z = 0; z < frameCount; z++)
    {
        deque[z] = -1;  
    } // represents empty frame
    
    for (int s = 0; s < streamCount; s++){
        isInQueue = false;
    for (int u = 0; u < frameCount; u++){
        if (refStream[s] == deque[u] ){
            isInQueue = true;
            
         }
       
 
    } // end of frameCount loop
         
         recentlyUsed = refStream[s];
         list.remove(recentlyUsed);
         list.push_front(recentlyUsed);
         leastRecentlyUsed = list.back();
         
         if (isInQueue == false){
          //  cout << list.size();
            if(deque[frameCount-1] != -1){
                
                replacementVal = leastRecentlyUsed;
                list.remove(leastRecentlyUsed);
                
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
    
    cout << "LRU incurred " << pageFaultCount << " page faults for this reference stream." << endl;
}




    
    /*
     * FIRST IN FIRST OUT 
     */

void fifo(deque<int> &deque, queue<int> &queue, int streamCount, std::deque<int> refStream, int frameCount){
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
    
    int streamCount = 0;
    int frameCount;
    int refNumber;
    int a = 0;
    ifstream myfile ("refstream.txt");
    
    // int refStream[streamCount];
    deque<int> refStream;
    deque<int> beladyFramePosition;
    list<int> beladyFrameInfo;
    deque<int> fifoFramePosition;
    queue<int> fifoFrameInfo;
    deque<int> lruFramePosition;
    list<int> lruFrameInfo;
    

    
    if (myfile.is_open()){
        myfile >> frameCount;
    
    while (myfile.good()){
        
        myfile >> refNumber;
        refStream.push_back(refNumber);
       streamCount++;
     }
        
       myfile.close();
   }
 
    
    
   cout << "The reference stream is: " << endl;
   for (int e = 0; e < streamCount; e++){
        
    cout << refStream[e] << " ";
    }
    cout << endl;
    
    lru(lruFrameInfo, lruFramePosition, streamCount, refStream, frameCount);
    
    /* 
    cout << endl;
    cout << "The reference stream is: " << endl;
    for (int e = 0; e < streamCount; e++){
        
    cout << refStream[e] << " ";
    }
    cout << endl;
    */
    
    fifo(fifoFramePosition, fifoFrameInfo, streamCount, refStream, frameCount);
    
    cout << endl;
    /*
    cout << "The reference stream is: " << endl;
    for (int e = 0; e < streamCount; e++){
        
    cout << refStream[e] << " ";
    }
    cout << endl;
    */
    
    belady(beladyFrameInfo, beladyFramePosition, streamCount, refStream, frameCount);
    
    return 0;
}