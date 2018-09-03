/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:50:23 by cpaquet           #+#    #+#             */
/*   Updated: 2018/05/08 11:16:48 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <limits.h>

# define HR ((t_coord*)(data->head_rooms->content))
# define HT ((t_tube*)(data->head_tubes->content))
# define THT ((t_tube*)(tmp_tubes->content))
# define THR ((t_coord*)(tmp_rooms->content))

typedef struct	s_tube
{
	char		*name_1;
	char		*name_2;
}				t_tube;

typedef struct	s_display
{
	int			id;
	int			index;
	char		**path;
}				t_display;

typedef struct	s_coord
{
	int				x;
	int				y;
	int				position;
	int				index;
	int				nbr_sons;
	int				distance;
	char			*room_name;
	struct s_coord	**sons;
}				t_coord;

typedef struct	s_ant
{
	int			id;
	int			length;
	char		**path;
	t_coord		*room;
}				t_ant;

typedef struct	s_sol
{
	int			nbr_path;
	int			comb_ok;
	int			cost;
	t_ant		**ant;
}				t_sol;

typedef struct	s_data
{
	char		flag_info;
	char		flag_path;
	char		flag_ant;

	int			ants_nbr;
	int			rooms_nbrs;
	int			comb_limit;

	int			max_cost;
	int			len_ant_list;

	int			sol_nbr;
	char		**maps;
	int			line_map;
	t_coord		*start_rooms;
	t_coord		*end_rooms;
	t_list		*head_rooms;
	t_list		*head_tubes;
	t_list		*ant_list;
	t_list		*ant_sol;
	t_list		*solution_list;
	t_list		*ant_dis;
}				t_data;

int				check_strend(t_data *data);
t_list			*delete_room(t_data *data, t_list *room);
int				ft_analyse_flag(t_data *data, int argc, char **argv);
int				get_info(t_data *data);
int				ft_check_coord(t_data *data);
void			check_son(t_data *data);
int				check_link_start_end(t_coord *start);
int				super_scoot(t_data *data);
int				combinatoire(t_data *data, t_ant *ant);
void			distribute(t_data *data);
int				check_room_dup(t_list *room, t_coord *new, char *name);
int				check_data(t_data *data);
int				check_line_info(char *line);
int				check_line(char *line);
int				check_comment(char *line);
int				check_roomcoord(t_list *room, t_coord *coord, char *name);
int				check_is_digit(char **tab);
int				check_name_tube(char **tab, t_data *data);

/*
** Functions from init.c
*/
int				init_solution_list(t_data *data);

/*
** Functions from combinatoire.c
*/
void			replace_comb(t_data *data, t_sol *solution, t_ant **comb);
int				calcul_cost(t_data *data, t_sol *solution, t_ant **comb);
int				verify_ant(t_ant **comb, t_ant *ant, int sol_nbr);

/*
** Functions from combinatoire2.c
*/
void			ft_distance(t_coord *room);
void			ft_print_path(t_ant *ant);
void			ft_create_first_ant(t_data *data);
int				ft_not_visited(t_ant *ant, t_coord *room);

/*
** Functions from tools.c
*/
int				search_start_end(t_data *data);
int				exclusive(char **path1, char **path2);
int				check_duplicate(t_ant *ant, t_list *ant_sol);
void			ft_sort_index(t_coord *room);
void			ft_sort_sol(t_sol *sol);

/*
** Functions from tools.c
*/
t_list			*delete_dis(t_data *data, t_list *dis);
t_list			*ft_delete_ant(t_list **list, t_list *ant, int flag);
void			ft_free1(t_data *data);
void			ft_free2(t_data *data);
int				free_double_tab(char ***data, int a);

#endif
