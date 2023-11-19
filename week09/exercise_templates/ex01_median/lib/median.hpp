#ifndef MEDIAN_HPP_
#define MEDIAN_HPP_


template <typename T>
auto median(T first, T second, T third) -> T {
    if((second > first && second < third) || (second < first && second > third)) {
        return second;
    }

    if((first > second && first < third) || (first < second && first > third)) {
        return first;
    }
    return third;
}


#endif /* MEDIAN_H_ */
