#include "sublist.h"

static int compare(int *list_a, int *list_b, size_t dim)
{
    size_t iter;

    iter = 0;
    while ((iter < dim) && (list_b[iter] == list_a[iter]))
        iter++;
    return (iter == dim) ? 1 : 0;
}

static int subl(int *list_a, int *list_b, size_t dim_a, size_t dim_b)
{
    int res;
    int top;
    int iter;

    top = dim_b - dim_a + 1;
    res = 0;
    iter = 0;
    if (dim_a == 0)
        res = 1;
    else
    {
        while (!res && (iter < top))
        {
            if (list_b[iter] == list_a[0])
                res = compare(list_b + iter, list_a, dim_a);
            iter++;
        }
    }
    return res;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count, size_t base_list_element_count)
{
    comparison_result_t res;

    res = UNEQUAL;
    if ((list_to_compare_element_count == base_list_element_count) &&
        ((list_to_compare_element_count == 0) || (compare(list_to_compare, base_list, base_list_element_count))))
        res = EQUAL;
    else if (list_to_compare_element_count < base_list_element_count)
        res = (subl(list_to_compare, base_list, list_to_compare_element_count, base_list_element_count)) ? SUBLIST : UNEQUAL;
    else
        res = (subl(base_list, list_to_compare, base_list_element_count, list_to_compare_element_count)) ? SUPERLIST : UNEQUAL;
    return res;
}
