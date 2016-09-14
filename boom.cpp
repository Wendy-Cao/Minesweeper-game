#include "boom.h"
#include<QPushButton>
extern    QList<tab *>m_posList;
QList<int> numbersList;  //随机数去重
boom::boom(QObject *parent) :
    QObject(parent)
{
}
void boom::set_ray_btn(int m,int n,int num)
{
    numbersList.clear();
    int p;
        for(int k=0;k<num;k++)
           {
               numbersList.append(qrand()%(m*n-1));
               bool flag=true;
               while(flag)
               {
                   for( p=0;p<k;p++)
                   {
                       if(numbersList[k]==numbersList[p])
                           break;
                   }
                   if(p<k)
                       numbersList[k]=rand()%10;
                   if(p==k)
                       flag=!flag;
               }
        }
    for(int id=0;id<num;id++)
    {
        qDebug()<<id<<endl;
        m_posList.at(numbersList[id])->val=-1;//随机步下s个雷
    }
for(int j=0;j<num;j++)
    {
        int i=numbersList[j];
        if(i==0)
    {
          if(m_posList.at(i+1)->val!=-1)
          m_posList.at(i+1)->val+=1;
          if(m_posList.at(i+8)->val!=-1)
           m_posList.at(i+8)->val+=1;
          if(m_posList.at(i+9)->val!=-1)
          m_posList.at(i+9)->val+=1;
      }
      if(i>=1 && i<=n-2)
      {
          if(m_posList.at(i-1)->val!=-1)
          m_posList.at(i-1)->val+=1;
          if(m_posList.at(i+1)->val!=-1)
          m_posList.at(i+1)->val+=1;
          if(m_posList.at(i+7)->val!=-1)
          m_posList.at(i+7)->val+=1;
          if(m_posList.at(i+8)->val!=-1)
          m_posList.at(i+8)->val+=1;
          if(m_posList.at(i+9)->val!=-1)
          m_posList.at(i+9)->val+=1;
      }
      if(i==(n-1))
      {
          if(m_posList.at(i+1)->val!=-1)
          m_posList.at(i+1)->val+=1;
          if(m_posList.at(i+7)->val!=-1)
          m_posList.at(i+7)->val+=1;
          if(m_posList.at(i+8)->val!=-1)
          m_posList.at(i+8)->val+=1;
      }
      if(i != 0 && i%n == 0 && i != ((m-1)*n))
      {
          if(m_posList.at(i-8)->val!=-1)
          m_posList.at(i-8)->val+=1;
          if(m_posList.at(i-7)->val!=-1)
          m_posList.at(i-7)->val+=1;
          if(m_posList.at(i+1)->val!=-1)
          m_posList.at(i+1)->val+=1;
          if(m_posList.at(i+8)->val!=-1)
          m_posList.at(i+8)->val+=1;
          if(m_posList.at(i+9)->val!=-1)
          m_posList.at(i+9)->val+=1;
      }
      for(int t = 1;t < (m-1);t++)
      {
      if(i > (t*n) && i < ((t+1)*n -1))
      {
          if(m_posList.at(i-1)->val!=-1)
          m_posList.at(i-1)->val+=1;
          if(m_posList.at(i+1)->val!=-1)
          m_posList.at(i+1)->val+=1;
          if(m_posList.at(i-7)->val!=-1)
          m_posList.at(i-7)->val+=1;
          if(m_posList.at(i-8)->val!=-1)
          m_posList.at(i-8)->val+=1;
          if(m_posList.at(i-9)->val!=-1)
          m_posList.at(i-9)->val+=1;
          if(m_posList.at(i+7)->val!=-1)
          m_posList.at(i+7)->val+=1;
          if(m_posList.at(i+8)->val!=-1)
          m_posList.at(i+8)->val+=1;
          if(m_posList.at(i+9)->val!=-1)
          m_posList.at(i+9)->val+=1;
    }
      }
      if(i != (n-1) && (i+1)%n == 0 && i!=(m*n) -1)
      {
          if(m_posList.at(i-9)->val!=-1)
          m_posList.at(i-9)->val+=1;
          if(m_posList.at(i-8)->val!=-1)
          m_posList.at(i-8)->val+=1;
          if(m_posList.at(i-1)->val!=-1)
          m_posList.at(i-1)->val+=1;
          if(m_posList.at(i+7)->val!=-1)
          m_posList.at(i+7)->val+=1;
          if(m_posList.at(i+8)->val!=-1)
          m_posList.at(i+8)->val+=1;
}
      if(i == (m-1)*n)
      {
          if(m_posList.at(i-8)->val!=-1)
          m_posList.at(i-8)->val+=1;
          if(m_posList.at(i-7)->val!=-1)
          m_posList.at(i-7)->val+=1;
          if(m_posList.at(i+1)->val!=-1)
          m_posList.at(i+1)->val+=1;
      }
      if(i > ((m-1)*n) && i < ((m*n)-1))
      {
          if(m_posList.at(i-7)->val!=-1)
          m_posList.at(i-7)->val+=1;
          if(m_posList.at(i-8)->val!=-1)
          m_posList.at(i-8)->val+=1;
          if(m_posList.at(i-9)->val!=-1)
          m_posList.at(i-9)->val+=1;
          if(m_posList.at(i-1)->val!=-1)
          m_posList.at(i-1)->val+=1;
          if(m_posList.at(i+1)->val!=-1)
          m_posList.at(i+1)->val+=1;
      }
      if(i== (m*n-1))
      {
          if(m_posList.at(i-8)->val!=-1)
          m_posList.at(i-8)->val+=1;
          if(m_posList.at(i-9)->val!=-1)
          m_posList.at(i-9)->val+=1;
          if(m_posList.at(i-1)->val!=-1)
          m_posList.at(i-1)->val+=1;
      }
    }
}

