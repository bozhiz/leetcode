#include <stdio.h>

    int steps;
    
static    void recursive(int n) {
        if(n-1 > 0)
            recursive(n-1);
        else if(n-1 == 0)
            steps++;
        
        if(n-2 > 0)
            recursive(n-2);
        else if(n-2 == 0)
            steps++;
    }

static    int climbStairs(int n) {
        steps = 0;
        recursive(n);
        return steps;
    }

int main(int argc, char *argv[])
{
	climbStairs(3);
	printf("%d\r\n", steps);
}
