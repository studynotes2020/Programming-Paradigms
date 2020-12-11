// From last lecture
void sellTickets(int agentID, int *numTicketsAll, Semaphore lock); // numTicketsAll is one global copy of tickets to sell

semaphore => sync counter var >= 0
SemaphoreWait(lock);  lock = 0
SemaphoreSignal(lock);  lock = 1
SemaphoreWait(lock);  lock = 0
SemaphoreWait(lock);  lock = -1 but lock not allowed go below 0

void sellTickets(int agentID, int *numTicketsAll, Semaphore lock)
{
    while (true) {
        SemaphoreWait(lock);
        if (*numTicketsAll == 0) break;
        (*numTickets)--; // this and line above are critical region
        SemaphoreSignal(lock); // release the lock
        printf("Sell a ticket");
        // sleep
    }
    SemaphoreSignal(lock); // accomodate the case of break
}

// Read/write data from internet. HTML always souced from various servers
char buffer[8];  // global buffer
Semaphore emptyBuffers(8); // if smaller number, writer leading reader will smaller overhead. if 1, alternate between read and write. if 0, deadlock
Semaphore fullBuffers(0); // if larger number, allow reader before writer

int main() 
{
    InitThreadPackage(false);
    ThreadNew("writer", writer, 0);
    ThreadNew("reader", reader, 0);
    // Problem arise when reader faster than writer
    RunAllThreads();
}

void writer()
{
    for (int i = 0; i < 40; i++) {
        char c = PrepareRandomChar();
        SemaphoreWait(emptyBuffers);  // if writer faster than reader emptyBuffers will decrease till 0, and blocked out from processor
        buffer[i%8] = c;
        SemaphoreSignal(fullBuffers);
    }
}

void reader()
{
    for (int i = 0; i < 40; i++) {
        SemaphoreWait(fullBuffers);
        char c = buffer[i%8];
        SemaphoreSignal(emptyBuffers);  // allow to read
        ProcessChar(c);
    }
}


// Philosophers dining problem
Semaphore forks[] = {1, 1, 1, 1, 1};
Semaphore numAllowedToEat(4); // to solve deadlock problem
void Philosopher(int id)
{
    for (int i = 0; i < 3; i++) {
        Think();
        SemaphoreWait(forks[id]);
        SemaphoreWait(forks[(id+1)%5]);
        Eat();
        SemaphoreSignal(forks[id]);
        SemaphoreSignal(forks[(id +1)%5]);
    }
}