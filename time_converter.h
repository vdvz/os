typedef	unsigned short			u16_t;
typedef	unsigned long			u32_t;
typedef	signed short			s16_t;
typedef	signed long			s32_t;

	// DEF: standard signed format
	// UNDEF: non-standard unsigned format
	#define	_XT_SIGNED

#ifdef	_XT_SIGNED
	typedef	s32_t                           xtime_t;
#else
	typedef	u32_t                           xtime_t;
#endif

struct tm
{       /* date and time components */
	BYTE	tm_sec;
	BYTE	tm_min;
	BYTE	tm_hour;
	BYTE	tm_mday;
	BYTE	tm_mon;
	u16_t	tm_year;
};

void xttotm(struct tm *t, xtime_t secs);
xtime_t xtmtot(struct tm *t);