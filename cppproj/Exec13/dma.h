#ifndef DMA_H
#define DMA_H
//Ќаследование и динамическое выделение пам€ти
#include <iostream>

//Ѕазовый класс, использующий динамическое выделение пам€ти
class baseDMA
{
private:
    char *label;
    int rating;
public:
    baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &os, const baseDMA &rs);
};

//производный класс без динамического выделени€ пам€ти
//деструктор не нужен
//используетс€ не€вный конструктор копировани€
//используетс€ не€вна€ операци€ присваивани€
class lacksDMA : public baseDMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
    lacksDMA(const char *c, const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &os, const lacksDMA &ls);
};

//ѕроизводный класс с динамическим выделением пам€ти
class hasDMA : public baseDMA
{
private:
    char *style;
public:
    hasDMA(const char *s = "none", const char *l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA &hs);
    friend std::ostream & operator<<(std::ostream &os, const hasDMA &rs);
};

#endif // DMA_H
