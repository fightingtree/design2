#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
//���x^(-1)mod p
int GetIne(int x, int p)
{
    for (int i = 0; i<p; i++)
    {
        if (x*i%p == 1)
        {
            x = i;
            break;
        }
    }
    return x;
}
int main()
{
    /*
    (1) ��������
    ����ѡȡ��ģ��n=26+10=36��k2Ϊѧ�ź�2λ��k1Ϊ��ѧ�ź�2λ�����������
    �ӽ��ܣ������Լ����ֵ�ȫƴ��ѧ�ţ��ٽ��ܡ�
    */
    int n = 36;
    string m, c;
    int buff[32], len = 0, k1 = 0, k2 = 0, k = 0;
    cout << "please input ciphertext" << endl;
    cin >> m;
    cout << "input k1:";
    cin >> k1;
    cout << "input k2:";
    cin >> k2;
    //������ת����10��������,0-9,a-z�ֱ����ʮ����0-36
    //����,M=(C-k2)*k1^(-1)
    for (int i = 0; m[i] != '\0'; i++)
    {
        //��ĸת10��������
        if (m[i] > '9')
            buff[i] = m[i] - 87;
        else
            buff[i] = m[i] - 48;//0ASCIIΪ48
        len++;
    }
    //��������,M=(C-k2)*k1^(-1)
    k = GetIne(k1, n);
    for (int i = 0; i < len; i++)
    {
        buff[i] = ((buff[i] - k2)*k) % n;
        if (buff[i] < 0)
            buff[i] += n;
        //buff[i] = (buff[i] * k1 + k2) % n;
    }
    //�����ֶ�ӦΪ���Ŀռ��ڵ��ַ�
    for (int i = 0; i < len; i++)
    {
        if (buff[i] < 10)
            m[i] = buff[i] + 48;
        else
            m[i] = buff[i] + 87;

    }
    cout << "plaintext" << endl;
    for (int i = 0; i<len; i++)
    {
        cout << m[i];
    }
    cout << endl;
    return 0;
}
