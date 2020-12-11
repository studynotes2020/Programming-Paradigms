#include <stdbool.h>

void sellTickets(int agentID, int numTicketsToSell);

int main()
{
    int numAgents = 10;
    int numTickets = 150;

    InitThreadPackage(false);
    for (int agent; agent <= numAgents; agent++) {
        char name[32];
        // print to char buffer, not to console
        sprintf(name, "Agent %d Thread", agent);
        ThreadNew(name, sellTickets, 2, agent, numTickets/numAgents);  // setup all the threads
    }
    RunAllThreads();  // lift the gate, threads run

    return 0;
}

void sellTickets(int agentID, int numTicketsToSell)
{
    while (numTicketsToSell > 0) {
        printf("Agent %d sells a tickets\n", agentID);
        numTicketsToSell--;
        if (RandomChance(0.1)) ThreadSleep(1000);
    }
    printf("Agent %d: All done\n", agentID);
}


void sellTickets2(int agentID, int *numTicketsAll, Semaphore lock); // one global copy of tickets to sell
int main2()
{
    int numAgents = 10;
    int numTickets = 150;
    Semaphore lock = semaphoreNew(xxx, 1);  // semaphore to support atomic ++/--, set lock to 1
    // if accidentally put 0 instead of 1, memory blocked since start, deadlock
    // if 2 race condition
    // SemaphoreWait(lock);  decrease lock to 0
    // SemaphoreSignal(lock);  increase lock to 1

    InitThreadPackage(false);
    for (int agent; agent <= numAgents; agent++) {
        char name[32];
        sprintf(name, "Agent %d Thread", agent);  // print to char buffer, not to console
        ThreadNew(name, sellTickets2, 3, agent, &numTickets, lock);  //setup all the threads
    }
    RunAllThreads();  // lift the gate, threads run

    return 0;
}

void sellTickets2(int agentID, int *numTicketsAll, Semaphore lock)
{
    while (true) {
        SemaphoreWait(lock);
        if (*numTicketsAll == 0) break;
        (*numTicketsAll)--;
        printf("Sold a ticket");
        SemaphoreSignal(lock);
    }
    SemaphoreSignal(lock); // bcs loop might break and didn't execute SemaphoreSignal()
}


