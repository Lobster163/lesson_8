#pragma once

template <typename T1, typename T2>
double check(T1 a, T2 b)
{
    try
    {
        if (b == 0)
            throw std::exception("division by 0");
        return a / b;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return -1.0f;
    }
}