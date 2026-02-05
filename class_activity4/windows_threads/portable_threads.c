#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d running\n", id);
    sleep(2);
    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t threads[6];
    int ids[6];

    for (int i = 0; i < 6; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    for (int i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed\n");
    return 0;
}

