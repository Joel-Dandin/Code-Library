/*
this program switches even and odd no
a = 5
no of bits to flip = 10
*/
unsigned int task(unsigned int x)
{
    for(int i=0;i<32;i+=2)
    {
        int i_bit = (x>>i)&1;
        int i_1_bit = (x>>(i+1))&1;

        x=x- (i_bit<<i) - (i_1_bit<<(i+1)) + (i_bit<<(i+1)) + (i_1_bit<<i);
    }
    return x;
}

int main()
{
    unsigned int no;
    printf("Enter the number to switch - ");
    scanf("%u",&no);

    unsigned int value = task(no);
    printf("the value that we can get is %u",value);
}
