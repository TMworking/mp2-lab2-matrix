#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int> a(3);
    a[0][1] = 5;
    TDynamicMatrix<int> b(a);
    EXPECT_EQ(a[0][1], b[0][1]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> a(3);
    TDynamicMatrix<int> b(a);
    a[0][1] = 5;
    EXPECT_EQ(0, b[0][1]);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicVector<int> a(3);
    EXPECT_EQ(3, a.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> a(3);
    a[0][1] = 5;
    EXPECT_EQ(5, a[0][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> a(3);
    ASSERT_ANY_THROW(a[0][-1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> a(3);
    ASSERT_ANY_THROW(a[0][4]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> a(3);
    ASSERT_NO_THROW(a = a);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> a(3), b(3);
    a[1][1] = 1;
    b = a;
    EXPECT_EQ(1, b[1][1]);

}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicVector<int> a(2), b(4);
    a = b;
    EXPECT_EQ(4, b.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> a(2), b(3);
    a[1][1] = 1;
    b = a;
    EXPECT_EQ(1, b[1][1]);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> a(3), b(3);
    a[1][1] = 1;
    b[1][1] = 1;
    EXPECT_EQ(true, a == b);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> a(2);
    EXPECT_EQ(true, a == a);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> a(2), b(3);
    a[1][1] = 1;
    b[1][1] = 1;
    EXPECT_EQ(false, a == b);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> a(3), b(3), c;
    a[1][1] = 1;
    b[1][1] = 1;
    c = a + b;
    EXPECT_EQ(2, c[1][1]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> a(2), b(3);
    ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> a(3), b(3), c;
    a[1][1] = 1;
    b[1][1] = 2;
    c = b - a;
    EXPECT_EQ(1, c[1][1]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> a(3), b(2);
    ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
    TDynamicMatrix<int> a(2), b(2), c;
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 1; b[0][1] = 2;
    b[1][0] = 3; b[1][1] = 4;

    c = a * b;

    EXPECT_EQ(7, c[0][0]);
    EXPECT_EQ(10, c[0][1]);
    EXPECT_EQ(15, c[1][0]);
    EXPECT_EQ(22, c[1][1]);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> a(3), b(2);
    ASSERT_ANY_THROW(a * b);
}