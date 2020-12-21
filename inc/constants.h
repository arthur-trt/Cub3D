/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:19:38 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/18 22:10:29 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/*
** CONFIG RESOLUTION
*/
# define MAX_WIDTH				3840
# define MAX_HEIGHT				2160

/*
** X EVENT AND MASK
*/
# define X_KEY_PRESS			2
# define X_M_KEY_PRESS			1
# define X_KEY_RELEASE			3
# define X_M_KEY_RELEASE		2
# define X_EXIT_WIN				17
# define X_M_STRUCTNOTIF		131072
# define X_FOCUSOUT				10
# define X_M_FOCUS				131072

/*
** KEY CODE
*/
# define KEY_W					119
# define KEY_S					115
# define KEY_A					97
# define KEY_D					100
# define KEY_LEFT				65361
# define KEY_RIGHT				65363
# define KEY_ESC				65307
# define KEY_SHIFT				65505

/*
** IDENTIFIER FOR TEXTURES
*/
# define NORTH		0
# define SOUTH		1
# define WEST		2
# define EAST		3
# define SPRITE		4
# define RESOLUTION	5
# define FLOOR		6
# define CEILLING	7

/*
** BOOLEAN DEFINITION
*/
# define SUCCESS	0
# define ERROR		-1

/*
** ERROR CODE
*/
# define WRONG_CLI	-1
# define NOT_CUB	-2
# define CANT_OPEN	-3
# define BAD_FORMAT	-4
# define CLOSE_FILE	-5
# define BAD_MAP	-6
# define BAD_PLAYER	-7
# define LOAD_TEXT	-8
# define CREATE_BMP	-9
# define BAD_RES	-10
# define NO_MAP		-11

#endif
