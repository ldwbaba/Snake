#include "Snake.h"


Snake::Snake(Food& food, int x):sFood(food)
{
    speed = x;
}

Snake::~Snake()
{

}


void Snake::initSnake(Point *tempP)
{
    destroySnake(tempP);
    addPoint(20, 15);
    addPoint(21, 15);
    addPoint(22, 15);
    addPoint(23, 15);
}
void Snake::initSnakeUdp(Point* tempP)
{
    destroySnake(tempP);
    addPointUdp(20, 18);
    addPointUdp(21, 18);
    addPointUdp(22, 18);
    addPointUdp(23, 18);
}

void Snake::addPoint(int a, int b)
{
    Point* newPoint = new Point;
    newPoint->x = a;
    newPoint->y = b;
    newPoint->next = NULL;

    if (pHead != NULL)
    {
        
        setPos(pHead->x, pHead->y);
       
        pHead->c = '=';
        Sleep(10);
        cout << pHead->c;
    }
    newPoint->next = pHead;
    pHead = newPoint;
    setPos(pHead->x, pHead->y);
   
    pHead->c = '@';
    Sleep(10);
    cout << pHead->c;
   
}
//画第二条蛇
void Snake::addPointUdp(int a, int b)
{
    Point* newPoint = new Point;
    newPoint->x = a;
    newPoint->y = b;
    newPoint->next = NULL;

    if (pHeadUdp != NULL)
    {

        setPos(pHeadUdp->x, pHeadUdp->y);
      
        pHeadUdp->c = '=';
        Sleep(10);
        cout << pHeadUdp->c;
    }
    newPoint->next = pHeadUdp;
    pHeadUdp = newPoint;
    setPos(pHeadUdp->x, pHeadUdp->y);
   
    pHeadUdp->c = '$';
    Sleep(10);
    cout << pHeadUdp->c;
    
}
void Snake::destroySnake(Point *tempP)
{
    Point* pCur = tempP;
    while (tempP != NULL)
    {
        pCur = tempP->next;
        delete tempP;//销毁pHead指向的节点而不是销毁指针

        tempP = pCur;
    }
}

void Snake::delPoint(Point *tempP)
{
    
    if (tempP == NULL || tempP->next == NULL)
    {
        return;
    }
    Point* pCur = tempP->next;
    Point* pPre = tempP;
    while (pCur->next != NULL)
    {
        pPre = pPre->next;
        pCur = pCur->next;
    }
    setPos(pCur->x, pCur->y);
    
    pCur->c = ' ';
    cout << pCur->c;

    delete pCur;
    pCur = NULL;

    pPre->next = NULL;
    Sleep(10);
    
}
bool Snake::eatFood(int x ,int y)
{
    bool T = FALSE;
    if (x == sFood.fHead->x && y == sFood.fHead->y)
    {
        T = TRUE;
    }
    return T;
}
//展示蛇
void Snake::showSnake(Point *tempP)
{
    Point* p;
    p = tempP;
    while (p)
    {
        setPos(p->x, p->y);
        Sleep(10);
        cout << p->c;
        p = p->next;
    }
 
}
//咬自己
void Snake::bitSelf(int x, int y, Point* tempP)
{
    Point* p;
    p = tempP;
    while (p)
    {
        if (p->x == x && p->y == y)
        {
            life = FALSE;
            return;
        }
        p = p->next;
    }
    Sleep(10);
};
//加速
void Snake::addSpeed(int grade)
{
    if (grade <= 100)
    {
        speed = 400;
    }
    else if (grade > 100 && grade <= 200)
    {
        speed = 300;
    }
    else if (grade > 20 && grade <= 300)
    {
        speed = 200;
    }
}