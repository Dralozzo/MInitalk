/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:49:59 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/21 18:10:02 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ditto(int sig, siginfo_t *info, void *str)
{
	static int	ciar;
	static int	ito;

	(void)str;
	if (sig == SIGUSR1)
	ciar += 1 << ito;
	ito++;
	if (ito == 8)
	{
		write(1, &ciar, 1);
		if (ciar == '\0')
			kill(info->si_pid, SIGUSR1);
			ciar = 0;
			ito = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	siga;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	siga.sa_sigaction = &ditto;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	sigemptyset(&siga.sa_mask);
	while (1)
		pause();
}

/*00000000, 1 << itto, 00000001, 0 << itto, 00000001, 1 << itto, 00000101,
 itto = 2,
1 << itto, 00001011*/
