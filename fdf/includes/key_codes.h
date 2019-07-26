/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:16:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 02:56:27 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H

/*
** https://eastmanreference.com/complete-list-of-applescript-key-codes
*/

/*
** EXIT
*/

# define ESC	53

/*
** MOVE
*/

# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126

/*
** ROTATE
*/

# define RIGHT_1		83
# define RIGHT_2		84
# define RIGHT_3		85
# define RIGHT_4		86
# define RIGHT_5		87
# define RIGHT_6		88
# define RIGHT_7		89
# define RIGHT_8		91
# define RIGHT_9		92
# define RIGHT_PLUS		69
# define RIGHT_MINUS	78

/*
** HEIGHT
*/

# define Z_UP			116
# define Z_DOWN			121

/*
** LETTERS
*/

# define LETTER_P		35
# define LETTER_I		34

# define LETTER_Q		12
# define LETTER_A		0
# define LETTER_W		13
# define LETTER_S		1
# define LETTER_E		14
# define LETTER_D		2

# define LETTER_T		17
# define LETTER_G		5
# define LETTER_Y		16
# define LETTER_H		4
# define LETTER_U		32
# define LETTER_J		38

/*
** OTHER
*/

# define ENTER			36
# define SPACE			49

# define LETTER_LN_UP(x)	(x == LETTER_Q || x == LETTER_W || x == LETTER_E)
# define LETTER_LN_DOWN(x)	(x == LETTER_A || x == LETTER_S || x == LETTER_D)
# define LETTER_LINE(x)		(LETTER_LN_UP(x) || LETTER_LN_DOWN(x))

# define LETTER_GR_UP(x)	(x == LETTER_T || x == LETTER_Y || x == LETTER_U)
# define LETTER_GR_DOWN(x)	(x == LETTER_G || x == LETTER_H || x == LETTER_J)
# define LETTER_GROUND(x)	(LETTER_GR_UP(x) || LETTER_GR_DOWN(x))

#endif
