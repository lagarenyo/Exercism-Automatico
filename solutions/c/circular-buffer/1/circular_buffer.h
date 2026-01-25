#ifndef CIRCULAR_BUFFER_H
# define CIRCULAR_BUFFER_H

# include <errno.h>
# include <stddef.h>
#include <stdlib.h>

typedef int			buffer_value_t;

typedef struct
{
	int				capacity;
	int				top;
	int				head;
	int				tail;
	buffer_value_t	*data;
}					circular_buffer_t;

circular_buffer_t	*new_circular_buffer(size_t capacity);
int					write(circular_buffer_t *buffer, buffer_value_t w_value);
int					overwrite(circular_buffer_t *buffer,
						buffer_value_t ow_value);
int					read(circular_buffer_t *buffer, buffer_value_t *r_value);
int					delete_buffer(circular_buffer_t *buffer);
int					clear_buffer(circular_buffer_t *buffer);
#endif
