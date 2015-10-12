# define _XOPEN_SOURCE 500
 
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
 
 
static inline
void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}
 
 
static
void fill_array(int arr[], size_t len) {
  for (size_t i = 0; i < len; i++)
    arr[i] = random() % 1000;
}
 
static
void print_array(int arr[], size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("| %3d ", arr[i]);
  }
  printf("|\n");
}
 

int* min_pos(int arr[], size_t len) {
  int min = arr[0];
  size_t j = 0;
     for (size_t i = 0; i < len; i++)
       {
	 if (min > arr[i])
          {
	    min = arr[i];
	    j = i;
	  }
       }
     return (&arr[j]);
}
 
void select_sort(int arr[], size_t len) {
  for(size_t i = 0; i < len; i++)
    {
      for(size_t j = 0; j < len; j++)
	{
	  if (arr[i]<arr[j])
	    {
	      swap(&arr[i],&arr[j]);
	    }
	}
    }
}
 
int is_sorted(int arr[], size_t len) {
  size_t i = 0;
  while((i<len-1) && (arr[i]<=arr[i+1]))
  {
     i = i+1;
  }
  return (i==len-1);
}
 
 
int main(int argc, char *argv[]) {
  if (argc < 2)
    errx(1, "missing array len");
  size_t len = strtoul(argv[1], NULL, 10);
  int *arr = malloc(len * sizeof (int));
  
  fill_array(arr, len);
  
  print_array(arr, len);
  
  printf("\n");
  
  select_sort(arr, len);
 
  print_array(arr, len);
 
  assert(is_sorted(arr, len));
  return 0;
}
