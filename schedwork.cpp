

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool schedule_helper(
    const AvailabilityMatrix& avail,
    const size_t maxShifts,
    DailySchedule& sched
);

bool checkValid(
	size_t& r, 
	size_t& c, 
	DailySchedule& sched
);

bool checkAvailability(
	size_t r, 
	size_t c,
	const AvailabilityMatrix& avail,
	const size_t maxShifts, 
	DailySchedule& sched
);

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

    //create empty template for sched
    for(size_t i = 0; i < avail.size(); i++){
        vector <Worker_T> temp;
        sched.push_back(temp);
        for(size_t j = 0; j < dailyNeed; j++){
            sched[i].push_back(INVALID_ID);
        }
    }

    return schedule_helper(avail, maxShifts, sched);

}



bool schedule_helper(
    const AvailabilityMatrix& avail,
    const size_t maxShifts,
    DailySchedule& sched
)
{
		size_t r = 0; //these vars get updated in the helper functions
		size_t c = 0; //these vars get updated in the helper function

    //if sched is valid throughout, return true
    if(checkValid(r, c, sched)){
        return true;
    }
		else{
			for(size_t i = 0; i < avail[0].size(); i++){
				//if worker is available, update schedule
				if(checkAvailability(r, i, avail, maxShifts, sched)){
					sched[r][c] = i;
					//recurse
					if(schedule_helper(avail, maxShifts, sched)){
						return true;
					}
					//if schedule ends up being invalid, change this worker's schedule back to invalid
					else{
						sched[r][c] = INVALID_ID;
					}
				}
			}
			return false;
		}

}


//this helper function determines if anything in the schedule is invalid
bool checkValid(
	size_t& r, 
	size_t& c, 
	DailySchedule& sched
)
{
  for(r = 0; r < sched.size(); r++){
  	for(c = 0; c < sched[r].size(); c++){
      if(sched[r][c] == INVALID_ID){
        return false;
       }
    }
  }  
	return true;
}


//this helper function checks if the worker hasn't exceeded the max num of shifts
bool checkAvailability(
	size_t r, 
	size_t c,
	const AvailabilityMatrix& avail,
	const size_t maxShifts, 
	DailySchedule& sched
)
{
	//if worker is not available on this day, return false
	if(avail[r][c] == false){
		return false;
	}
	//worker is available, now check if they already have too many shifts
	else{
		size_t counter = 0;
		for(size_t i = 0; i < sched.size(); i++){
			for(size_t j = 0; j < sched[0].size(); j++){
				if(sched[i][j] == c){
					counter++;
				}
			}
		}

		if(counter < maxShifts){
			return true;
		}
		else{
			return false;
		}
	}
}

