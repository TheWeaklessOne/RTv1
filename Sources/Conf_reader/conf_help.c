/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:45:06 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/07 17:14:37 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

void		conf_help(void)
{
	printf("Each *.conf file must contain at least one object.\nPossible"
			" objects: cone, plane, sphere and cylinder.\nPossible fields"
			" for every object:\n\tposition - object position in scene, have to"
			" be defined for every object.\n\tradius - object radius, have to"
			" be defined for sphere, cone and cylinder.\n\tcolor - object color"
			", by default is 42, 42, 42.\n\tspecular - object specular, by "
			"default is 0.\n\tnormal - object normal, have to be defined for"
			" cone, plane and cylinder.\nAlso *.conf file can contain lighting"
			". Possible lighting types: point_light, ambient_light, directional"
			"_light.\nPossible fields for every lighting:\n\tintensity - "
			"lighting intensity, have to be defined for every lighting. Total"
			" lighting intensity can't be more than 1.0.\n\t"
			"position - lighting position, have to be defined for ambient_light"
			" and directional_light.\n");
}
