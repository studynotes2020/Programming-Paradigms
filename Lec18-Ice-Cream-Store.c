/*
cashier
10 customers ask for random number of cone, 1 to 4
clerks 10 - 40
Manager

customers ask clerks for cones then only go to cashier

only one clerk can access manager office at a time

clerk need manager consent to dispatch cones

customer --> clerk --> manager --> clerk --> customer --> cashier


*/

int main() 
{
    int totalCones = 0;
    InitThreadPackage();
    SetupSemaphores();
    for(int i = 0; i < 10; i++) {
        int numCones = RandomInteger(1, 4);
        ThreadNew(customer, 1, numCones);
        totalCones += numCones;
    }
    ThreadNew(cashier, 0); // take 0 parameter
    ThreadNew(Manager, 1, totalCones);
    RunAllThreads();
    FreeSemaphores();

    return 0;
}

struct inspection {
    // initialization is done in SetupSemaphores
    bool passed;  // false
    semaphore requested; // 0
    semaphore finished; // 0
    semaphore lock; // 1 so that 1 clerk can get in
} inspection;

void manager(int totalConesNeeded) {
    int numApproved = 0;
    int numInspected = 0;
    while (numApproved < totalConesNeeded) {
        sw(inspection.requested);  // semaphore wait
        numInspected++;
        inspection.passed = RandomChange(0, 1);
        if (inspection.passed)
            numApproved++;
        ss(inspection.finished);  // semaphore signal
    }
}

void clerk(semaphore semaToSignal) {
    bool passed = false;
    while(!passed) {
        MakeCone();
        sw(inspection.lock);  //semaphore wait
        ss(inspection.requested);  // wait till finished 
        sw(inspection.finished);
        passed = inspection.passed;
        ss(inspection.lock); // release lock
    }
    ss(semaToSignal);

}

void customer(int numCones) {
    Browsing();  // just wasting cpu time
    Semaphore clerksDone; // 0
    for (int i = 0; i < numCones; i++) {
        ThreadNew(clerk, 1, clerksDone);
    }
    for(int i = 0; i < numCones; i++) {
        sw(clerksDone);
    }
    semaphoreFree(clerksDone);
    WalkToCashier();
    sw(line.lock);
    int place = line.number++;
    ss(line.lock);
    ss(line.requested);
    sw(line.customers[place]);
}

struct line {
    int number; // 0
    semaphore requested; // 0
    semaphore customers[10]; // each semaphore for each customer
    semaphore lock; // 1
    // need lock for number
} line;

void cashier() {
    for(int i = 0; i < 10; i++) {
        sw(line.requested);
        checkout(i);
        ss(line.customers[i]);
    }
}






