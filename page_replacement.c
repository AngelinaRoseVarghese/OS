#include <stdio.h>
int main() 
{
    int length, frames,i,j,replace = 0, far = -1, k,found = 0;
    printf("Enter no.of page frames and length of reference string: ");
    scanf("%d%d", &frames, &length);
    int ref[length],lru[frames], lastUsed[frames], lruFaults = 0,opt[frames], optFaults = 0,fifo[frames], fifoFaults = 0, next = 0;
    printf("Enter the reference string (numbers 0-9):\n");
    for(i = 0; i < frames; i++) 
    {
        fifo[i] = -1;
    }
    for(i = 0; i < length; i++)
    {
        scanf("%d", &ref[i]);
    }
    for(i = 0; i < length; i++)
    {
        int found = 0;
        for(j = 0; j < frames; j++) 
        {
            if(fifo[j] == ref[i]) 
            {
                found = 1;
            }
        }
        if(!found) 
        {
            fifo[next] = ref[i];
            next = (next + 1) % frames;
            fifoFaults++;
        }
    }
    printf("FIFO Page Faults: %d\n", fifoFaults);
    for(i = 0; i < frames; i++) 
    {
        lru[i] = -1; 
        lastUsed[i] = -1; 
    }
    for(i = 0; i < length; i++) 
    {
        int found = -1;
        for(j = 0; j < frames; j++) 
        {
            if(lru[j] == ref[i]) 
            {
                found = j;
            }
        }
        if(found != -1)
        {
            lastUsed[found] = i;  // update usage
        } 
        else
        {
            int lruIndex = 0, min = lastUsed[0];
            for(j = 1; j < frames; j++) 
            {
                if(lastUsed[j] < min) 
                {
                    min = lastUsed[j]; 
                    lruIndex = j;
                }
            }
            lru[lruIndex] = ref[i];
            lastUsed[lruIndex] = i;
            lruFaults++;
        }
    }
    printf("LRU Page Faults: %d\n", lruFaults);
    for(i = 0; i < frames; i++) 
    {
        opt[i] = -1;
    }
    for(i = 0; i < length; i++)
    {
        found = 0; 
        for(j = 0; j < frames; j++) 
        {
            if(opt[j] == ref[i]) 
            {
                found = 1;
                break;
            }
        }
        if(!found) 
        {
             far = -1; 
             replace = 0;
            for(j = 0; j < frames; j++) 
            {
                for(k = i + 1; k < length; k++) 
                {
                    if(opt[j] == ref[k])
                    {
                        break;
                    }
                }
                if(k > far) 
                {
                    far = k;
                    replace = j; 
                }
            }
            opt[replace] = ref[i];
            optFaults++;
        }
    }
    printf("Optimal Page Faults: %d\n", optFaults);
    return 0;
}
