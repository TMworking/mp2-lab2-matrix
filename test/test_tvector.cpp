#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> a(5);
	a[1] = 1;
	a[2] = 2;
	TDynamicVector<int> b(a);
	for (int i = 0; i < a.size(); i++)
	{
		EXPECT_EQ(a[i], b[i]);
	}
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> a(5);
	TDynamicVector<int> b(a);
	a[0] = 5;
	EXPECT_EQ(0, b[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> a(5);
	ASSERT_ANY_THROW(a[-1]);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> a(5);
	ASSERT_ANY_THROW(a[100]);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> a(5);
	ASSERT_NO_THROW(a = a);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> a(5), b(5);
	a[1] = 1;
	b = a;
	EXPECT_EQ(1, b[1]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> a(2), b(5);
	b = a;
	EXPECT_EQ(a.size(), b.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> a(2), b(5);
	a[1] = 1;
	b = a;
	EXPECT_EQ(a[1], b[1]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> a(5), b(5);
	a[1] = 1;
	b[1] = 1;
	EXPECT_EQ(true, a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(5);
	EXPECT_EQ(true, a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> a(2), b(5);
	EXPECT_EQ(false, a == b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> a(5);
	a[1] = 1;
	a = a + 2;
	EXPECT_EQ(2, a[0]);
	EXPECT_EQ(3, a[1]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> a(5);
	a[1] = 2;
	a = a - 1;
	EXPECT_EQ(-1, a[0]);
	EXPECT_EQ(1, a[1]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> a(5);
	a[1] = 2;
	a = a * 2;
	EXPECT_EQ(4, a[1]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5), c;
	a[1] = 1;
	b[1] = 1;
	b[2] = 2;
	c = a + b;
	EXPECT_EQ(2, c[1]);
	EXPECT_EQ(2, c[2]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(2), b(5);
	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5), c;
	a[1] = 1;
	b[1] = 1;
	b[2] = 2;
	c = a - b;
	EXPECT_EQ(0, c[1]);
	EXPECT_EQ(-2, c[2]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(2), b(5);
	ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5);
	a[1] = 1; a[2] = 2;
	b[1] = 1; b[2] = 2;

	EXPECT_EQ(5, a * b);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(2), b(5);
	ASSERT_ANY_THROW(a * b);
}

