# AOE Network

## Idea
1. Use topological sort to determine the order of the events.
2. Get the earliest event time(ee) from the first event to the last event.
3. Get the latest event time(le) from the last event to the first event.
4. Calculate the slack time between two events.

## Variables
* int n: the # of activities
* int maxVertex: the maximum # of vertices(events)
* bool adjMatrix[][]: the value of adjMatrix[u][v] is true if edge(transition) <u, v> exists
* duration[][]: the duration from one event to another
* int ee[]: the earliest event time an event can occur
* int le[]: the latest event time an event must occur without increasing the project duration
* int sortedList[]: the sorted list of events after topological sorting
* struct Activity act[]: stores several data
    * int startVertex: the start event
    * int endVertex: the end event
    * int e: the earliest time the activity can occur
    * int l: the lastest time the activity must occur
    * int slack: longest slack time before starting the activity, note that slack = l - e

## Functions
*   ```cpp
    int *topological_sort(bool **adjMatrix, int maxVertex);
    ```
    1. Find an event which doesn't have any predecessor.
    2. Add the event to the sorted list and mark it as "marked".
    3. If all the events are marked, finish the sorting procedure and return the sorted list. Otherwise, go back to step 1.
<br><br>
*   ```cpp
    void getEarliestEventTime(int *ee, int *sortedList, bool **adjMatrix, int **duration, int maxVertex);
    ```
    1. Update the earliest event time of an event if:<br>
        ee[currentEvent] < ee[previousEvent] + duration[previousEvent][currentEvent]
    2. Repeat step 1 until the earliest event time of every event in the sorted list is updated.
<br><br>
*   ```cpp
    void getLatestEventTime(int *le, int *sortedList, bool ** adjMatrix, int **duration, int maxVertex);
    ```
    1. Update the latest event time of an event if:<br>
    le[currentEvent] > le[currentEvent] - duration[previousEvent][currentEvent]