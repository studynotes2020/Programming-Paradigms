/* 
Dining Philosophers

Five philosophers sitting in circle. 
Each philosopher eats his own meal.
One fork in the middle of each philosopher
Each philospher can only eat when there is one fork on each side
In other words, two philosopher competing for one fork

*/

Semaphore forks[] = {1,1,1,1,1};
Semaphore numAllowedToEat(4);  // 5 won't work
// 4 works because at least one person doesn't grab forks from both side

void philosopher(int id)
{
    for (int i = 0; i < 3; i++) {
        think();
        sw(numAllowedToEat);
        sw(forks[id]);  // semaphore wait
        sw(forks[(id + 1) % 5]);
        eat();
        ss(forks[id]);  // semaphore signal
        ss(forks[(id + 1) % 5]);
        ss(numAllowedToEat);
    }
    think();
}

int DownloadSingleFile(const char *server, const char *path)
{

}

int DownloadAllFiles(const char *server, const char *files[], int n) {
    int totalBytes = 0;
    Semaphore lock = 1;
    for (int i = 0; i < n; i++) {
        ThreadNew(dontcare, DownloadHelper, 4, server, files[i], &totalBytes, lock);
    }

    return totalBytes;
}

void DownloadHelper(const char *server, const char *path, int *numBytesp, Semaphore lock) {
    // if this is in critical region, it will still run, but slower, bcs this become running sequentially
    int bytesDownloaded = DownloadSingleFile(server, path);
    sw(lock);
    (*numBytesp) += bytesDownloaded;  // critical region
    ss(lock);

}