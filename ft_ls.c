/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 03:35:33 by kdeloise          #+#    #+#             */
/*   Updated: 2019/10/26 05:58:19 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	zerostruct(t_lc	len)
{
	len.c2 = 0;
	len.c3 = 0;
	len.c4 = 0;
	len.major = 0;
	len.minor = 0;
	len.c5 = 0;
	len.total = 0;
//	return(len);
}

t_lc	total(DIR	*dp, int x, char *name, t_lc len)
{
	struct stat		stbuf;
	struct dirent	*infdir;

	zerostruct(len);
	while ((infdir = readdir(dp)))
	{
		if (x == 1)
			lstat(infdir->d_name, &stbuf);
		else
			lstat(ft_strjoin(ft_strjoin(name, "/"), infdir->d_name), &stbuf);
		len.total += stbuf.st_blocks;
		if (len.c2 < ft_lennbr(stbuf.st_nlink))
			len.c2 = ft_lennbr(stbuf.st_nlink);
		if (len.c3 < ft_strlen(getpwuid(stbuf.st_uid)->pw_name))
			len.c3 = ft_strlen(getpwuid(stbuf.st_uid)->pw_name);
		if (len.c4 < ft_strlen(getgrgid(stbuf.st_gid)->gr_name))
			len.c4 = ft_strlen(getgrgid(stbuf.st_gid)->gr_name);
		if (len.major < ft_lennbr(major(stbuf.st_rdev)) && (S_ISCHR(stbuf.st_mode) || S_ISBLK(stbuf.st_mode)))
			len.major = ft_lennbr(major(stbuf.st_rdev));
		if (len.minor < ft_lennbr(minor(stbuf.st_rdev)))
			len.minor = ft_lennbr(minor(stbuf.st_rdev));
		if (len.c5 < ft_lennbr(stbuf.st_size))
			len.c5 = ft_lennbr(stbuf.st_size);
	}
	return (len);
}

char	*drwx(int mode)
{
	char	*chmod;
	char	*str;
	int		i;

	chmod = "drwxrwxrwx";
	i = strlen(chmod) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (S_ISDIR(mode))
		str[0] = 'd';
	else if (S_ISLNK(mode))
		str[0] = 'l';
	else if (S_ISBLK(mode))
		str[0] = 'b';
	else if (S_ISCHR(mode))
		str[0] = 'c';
	else if (S_ISFIFO(mode))
		str[0] = 'p';
	else if (S_ISSOCK(mode))
		str[0] = 's';
	else
		str[0] = '-';
	str[--i] = '\0';
	while (i-- > 1)
	{
		str[i] = mode % 2 + '0';
		if (str[i] == '1')
			str[i] = chmod[i];
		else
			str[i] = '-';
		mode = mode / 2;
	}
	return (str);
}

void	chtime(char *time, long long year)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	if (year < 15768000)
	{
		while (i != 16)
			time[j++] = time[i++];
	}
	else
	{
		while (j != 7)
			time[j++] = time[i++];
		time[++j] = ' ';
		time[j++] = time[20];
		time[j++] = time[21];
		time[j++] = time[22];
		time[j++] = time[23];
	}
	time[j] = '\0';
}

int		main(int argc, char **argv)
{
	int				i;
	DIR				*dp;
	struct dirent	*infdir;
	struct stat		stbuf;
	struct passwd	*uid;
	struct group	*gid;
	char			*time1;
	char			*buf;
	t_lc			len;
	long long		year;

	
	i = 1;
	if (argc == 1)
	{
		argv[i] = ".";
		dp = opendir(argv[i]);
		len = total(dp, argc, argv[i], len);
		closedir(dp);
		dp = opendir(argv[i]);
	}	
	else
	{
		lstat(argv[i], &stbuf);
		if (S_ISDIR(stbuf.st_mode))
		{
			dp = opendir(argv[i]);
			len = total(dp, argc, argv[i], len);
			closedir(dp);
			dp = opendir(argv[i]);
		}
		else
		{
			time1 = ctime(&stbuf.st_ctime);
			chtime(time1, year);
			printf("%s	", drwx(stbuf.st_mode));
			printf("%d	", stbuf.st_nlink);
			uid = getpwuid(stbuf.st_uid);
			printf("%s	", uid->pw_name);
			gid = getgrgid(stbuf.st_gid);
			printf("%s	", gid->gr_name);
			if (S_ISCHR(stbuf.st_mode))
			{
				printf("%d,	", major(stbuf.st_rdev));
				printf("%d	", minor(stbuf.st_rdev));
			}
			else
				printf("%lld	", stbuf.st_size);
			printf("%s	", time1);
			printf("%s	\n", argv[i]);
			exit (0);
		}
	}
	printf("total %lld\n", len.total);
	while ((infdir = readdir(dp)))
	{
		if (argc == 1)
			lstat(infdir->d_name, &stbuf);
		else
			lstat(ft_strjoin(ft_strjoin(argv[i], "/"), infdir->d_name), &stbuf);
		time1 = ctime(&stbuf.st_ctime);
		// printf("-->>%s<<--", time1);
		year = time(NULL) - stbuf.st_ctime;
//		printf("  %lld    ", year);
		chtime(time1, year);
		printf("%s  ", drwx(stbuf.st_mode));
		printf("%*d ", len.c2, stbuf.st_nlink);
		uid = getpwuid(stbuf.st_uid);
		printf("%-*s  ",len.c3, uid->pw_name);
		gid = getgrgid(stbuf.st_gid);
		printf("%-*s  ",len.c4, gid->gr_name);
		if (S_ISCHR(stbuf.st_mode) || S_ISBLK(stbuf.st_mode))
		{
			printf(" ");
			printf("%*d, ", len.major, major(stbuf.st_rdev));
			printf("%*d ", len.minor, minor(stbuf.st_rdev));
		}
		else
		{
			if ((len.major > 0 || len.major > 0) && (len.major + len.minor + 2) > len.c5)
				printf(" %*lld ", (len.major + len.minor + 2), stbuf.st_size);
			else
				printf("%*lld ", len.c5, stbuf.st_size);
		}
		printf("%s ", time1);
		printf("%s", infdir->d_name);
		if (drwx(stbuf.st_mode)[0] == 'l')
		{
			buf = ft_strnew(1025);
			readlink(ft_strjoin(ft_strjoin(argv[i], "/"), infdir->d_name), buf, 1024);
			buf[strlen(buf)] = '\0';
			printf(" -> %s", buf);
			free (buf);
		}
		printf("\n");
	}
	closedir(dp);
	return (0);
}
