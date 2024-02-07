/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:47:22 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/07 17:26:04 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int cmp(char *str1, char *str2)
{
    int i = 0; 
    int j = 0;
    if (str1[i] == '+')
    {
        if (str2[j] != '+')
            i++;
    }
    else
    {
        if (str2[j] == '+')
            j++;
    }
    while (str1[i] != '\0' && str2[j] != '\0' && str1[i] == str2[j]) 
    {
        i++;
        j++;
    }
    return (str1[i] - str2[j]);
}
int not_duplicate(char **argv)
{
    int i;
    int j;
     
    i = 1;
    while (argv[i])
    {
        j = 1;
        while (argv[j])
        {
            if( j != i && cmp (argv[i],argv[j]) == 0)
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}
int is_sign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    else
        return(0);
}
int zeros(char *argv)
{
    int i = 0;
    while (argv[i] && argv[i] == '0')
    {   
        i++;
        return(1);
    }
    return(0);  
}
int not_good_input(int *str)
{
    if (is_sign(*str))
        str++;
    if (str < 0 || *str > 9)
        return (1);
    while (*str)
    {
        if (*str < 0 || *str > 9)
            return (1);
        // int zero = 0;
        // zero += zeros(str);
        // if(zero >= 1)
        //  return (1);
        str++;
    }
    return (0);
}
/*
#include "push_swap.h"
int cmp(char *str1, char *str2)
{
    int i = 0; 
    int j = 0;
    if (str1[i] == '+')
    {
        if (str2[j] != '+')
            i++;
    }
    else
    {
        if (str2[j] == '+')
            j++;
    }
    while (str1[i] != '\0' && str2[j] != '\0' && str1[i] == str2[j]) 
    {
        i++;
        j++;
    }
    return (str1[i] - str2[j]);
}
int not_duplicate(char **argv)
{
    int i;
    int j;
     
    i = 1;
    while (argv[i])
    {
        j = 1;
        while (argv[j])
        {
            if( j != i && cmp (argv[i],argv[j]) == 0)
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}
int is_sign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    else
        return(0);
}
int zeros(char *argv)
{
    int i = 0;
    while (argv[i] && argv[i] == '0')
    {   
        i++;
        return(1);
    }
    return(0);  
}
int not_good_input(char *str)
{
    if (is_sign(*str))
        str++;
    if (*str < '0' || *str > '9')
        return (1);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (1);
        // int zero = 0;
        // zero += zeros(str);
        // if(zero >= 1)
        //  return (1);
        str++;
    }
    return (0);
}
*/