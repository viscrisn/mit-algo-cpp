    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #define BS 64*1024

    char ibuffer[BS];
    int ibuffer_offset=0;
    int ibuffer_size=0;
    char obuffer[BS];
    int obuffer_offset=0;
    static int inline fastread()
    {
        int r=0, s=1;
        while(1)
        {
            if(ibuffer_offset >= ibuffer_size)
            {
                ibuffer_size = read(0, ibuffer, BS);
                ibuffer_offset = 0;
            }
            if(ibuffer[ibuffer_offset] < 48)
            {
                if(s) ibuffer_offset++;
                else return r;
            }
            else
            {
                s = 0;
                r = r * 10 + ibuffer[ibuffer_offset++]-48;
            }
        }
    }
    void inline flush()
    {
        write(1, obuffer, obuffer_offset);
        obuffer_offset = 0;
    }
    static const char *rd[31] =
    {
    "1\n", "2\n", "4\n", "8\n", "16\n", "32\n", "64\n", "128\n", "256\n", "512\n", "1024\n",
    "2048\n", "4096\n", "8192\n", "16384\n", "32768\n", "65536\n", "131072\n", "262144\n",
    "524288\n", "1048576\n", "2097152\n", "4194304\n", "8388608\n", "16777216\n",
    "33554432\n", "67108864\n", "134217728\n", "268435456\n", "536870912\n"
    };
    static const int rl[31] =
    {
        2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8,     8, 9, 9, 9, 10, 10, 10
    };

    static void inline fastprint(int v)
    {
        if(obuffer_offset > BS - 11)
        {
            flush();
        }
        memcpy(obuffer + obuffer_offset, rd[v], rl[v]);
        obuffer_offset += rl[v];
    }

    static const int mdbbp[32] =
    {
        0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
        8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
    };

    int lg2(int v)
    {
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        return mdbbp[(unsigned int)(v * 0x07C4ACDDU) >> 27];
    }

    int main()
    {
        int c = fastread();
        while(c-->0)
        {
            fastprint(lg2(fastread()));
        }
        flush();
        return 0;
    }
