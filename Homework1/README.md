# Homework1 Students

http://fm.zju.edu.cn/showProblem.php?cid=113&pid=1271

题目描述 Assignment Requirment:

Write a program that asks you 10 records of students. Each record consists of a name (w/o space), and scores for three courses (in integer, 1 to 5). Output a list as the next page and calculate average score (in float) of each student and each course. Output the lowest and highest score for each course.

```
no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
10      J.Jon   5       4       3       4
        average 3.8     3.4     3.6
        min     2       2       1
        max     5       5       5
```

----

# 文件描述 File System:

**Record.h**

一条学生的记录，对应上述输出的一行

```
class Record{
private:
    string name;
    int* score;
    int len;//how many score in this record, actually using len+1 memory units (no using score[0])
public:
    Record(int ilen);
    ~Record();
    void inputname(string& iname);
    string& getname();
    bool inputscore(int idx,int iscore);
    int getscore(int idx);
    double getaverage();
};
```

**Students.h**

整张数据表，一个学生平均分为RecordAverage，一个科目平均分为ScoreAverage

```
class Students{
private:
    pRecord* data;//an array, the element is pointer to one Record 
    int len;//how many record in this Students, actually using len+1 memory units (no using data[0])
    int rlen;//how many score in each record
public:
    Students(int ilen,int irlen);
    ~Students();
    int get_rlen();
    void inputRecordName(int idx,string& name);
    void inputRecordScore(int idx,int rdx,int score);//inputRecordScore(2,1,4) means No.2 Studnets's score1=4
    int getRecordScore(int idx,int rdx);
    double getRecordAverage(int idx);
    string& getRecordName(int idx);
    double getScoreAverage(int rdx);
    int getScoreMin(int rdx);
    int getScoreMax(int rdx);
};
```