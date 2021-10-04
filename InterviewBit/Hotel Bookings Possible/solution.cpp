/*

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 

*/

#include <bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{
   vector<pair<int, int>> ans;

   int n = arrive.size();

   // create a common vector both arrivals
   // and departures.
   for (int i = 0; i < n; i++)
   {
      ans.push_back(make_pair(arrive[i], 1));
      ans.push_back(make_pair(depart[i], 0));
   }

   // sort the vector
   sort(ans.begin(), ans.end());

   int curr_active = 0, max_active = 0;

   for (int i = 0; i < ans.size(); i++)
   {

      // if new arrival, increment current
      // guests count and update max active
      // guests so far
      if (ans[i].second == 1)
      {
         curr_active++;
         max_active = max(max_active,
                          curr_active);
      }

      // if a guest departs, decrement
      // current guests count.
      else
         curr_active--;
   }

   // if max active guests at any instant
   // were more than the available rooms,
   // return false. Else return true.
   return (K >= max_active);
}