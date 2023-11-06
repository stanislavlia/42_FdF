#include	"fdf.h"


void	free_matrix(t_matrix	*matrix_ptr)
{
	int	i;

	i = 0;
	while (i < (*matrix_ptr).m)
	{

		free((*matrix_ptr).rows[i].values);
		i++;
	}
	free((*matrix_ptr).rows);
}


// void free_matrix(t_matrix *matrix_ptr)
// {
//     int i;

//     // Check if the matrix pointer is NULL
//     if (matrix_ptr == NULL) {
//         return;
//     }

//     // Free each row
//     for (i = 0; i < matrix_ptr->m; i++) {
//         // Check if the row pointer is NULL
//         if (matrix_ptr->rows[i].values != NULL) {
//             free(matrix_ptr->rows[i].values);
//             matrix_ptr->rows[i].values = NULL; // Avoid dangling pointer
//         }
//     }

//     // Free the rows array
//     free(matrix_ptr->rows);
//     matrix_ptr->rows = NULL; // Avoid dangling pointer

//     // Here you might also want to free the matrix_ptr itself if it was dynamically allocated
//     // and set it to NULL if the function signature allows for it (e.g., by passing a double pointer).
// }
