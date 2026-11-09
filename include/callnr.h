/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#ifndef CALLNR_H
#define CALLNR_H

enum {

	EXIT=1,FORK,READ,WRITE,OPEN,CLOSE,WAIT,CREAT,LINK,UNLINK,
	WAITPID,CHDIR,TIME,MKNOD,CHMOD,CHOWN,STAT,LSEEK,GETPID,
	MOUNT,UMOUNT,SETUID,GETUID,STIME,ALARM,FSTAT,PAUSE,UTIME,
	ACCESS,SYNC,KILL,RENAME,MKDIR,RMDIR,DUP,PIPE,TIMES,SETGID,
	GETGID,SIGNAL,IOCTL,FNCTL,EXEC,UMASK,CHROOT,SETSID,GETSID,

	SIGACTION,SIGSUSPEND,SIGPENDING,SIGPROCMASK,SIGRETURN,

	HALT,REBOOT,

	LAST_CALL,
};

#endif
