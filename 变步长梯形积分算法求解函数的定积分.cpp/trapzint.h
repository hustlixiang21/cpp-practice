//
// Created by lixiang on 2022/8/6.
//

#ifndef _CPP_TRAPZINT_H
#define _CPP_TRAPZINT_H


class Function
{
public:
    virtual double operator()(double x) const = 0;
    virtual ~Function()= default;
};

class MyFunction : public Function
{
public:
    virtual double operator()(double x) const;
};

class Integration
{
public:
    virtual double operator()(double a, double b, double eps) const = 0;
    virtual ~Integration()= default;
};
class Trapz : public Integration
{
public:
    Trapz(const Function &f) : f(f) {}
    double operator()(double a, double b, double eps) const override;

private:
    const Function &f;
};

#endif //_CPP_TRAPZINT_H
