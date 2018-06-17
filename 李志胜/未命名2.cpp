    #include<iostream>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    int wordTot, _max = 0;
    struct words
    {
        int left = 2, tail = 0;            //剩余的使用次数 单词实际长度
        char word[101];                    //内容
    }words[22];
    int juj(char a[], char b[])
    {
        int al = strlen(a), bl = strlen(b), j;
        bool flag = true;
        for (int i = 1; i < al && i < bl; i++)
        {
            flag = true;
            for (j = 0; j < i; j++)
                if (a[al - i + j] != b[j]) { flag = false; break; }
            if (flag)
                return i;
        }
        return 0;
    }
    void dfs(char tail[], int num)
    {
        _max = max(_max, num);        //更新最大值
        int a;                        //两个单词重合部分的长度
        for (int i = 0; i < wordTot; i++)
            if (words[i].left > 0)
            {
                a = juj(tail, words[i].word);
                if (a != 0)            //判断是否符合题意
                {
                    words[i].left--;
                    dfs(words[i].word, num + words[i].tail - a);        //下一步搜索
                    words[i].left++;
                }
            }
    }
    int main()
    {
        char start;
        cin >> wordTot;
        for (int i = 0; i < wordTot; i++)
        {
            cin >> words[i].word;
            words[i].tail = strlen(words[i].word);
        }
        cin >> start;
        for (int i = 0; i < wordTot; i++)
            if (words[i].word[0] == start)
            {
                words[i].left--;
                dfs(words[i].word, words[i].tail);        //目前龙中最后一个单词 长度
                words[i].left++;
            }
        cout << _max << endl;
        return 0;
}
