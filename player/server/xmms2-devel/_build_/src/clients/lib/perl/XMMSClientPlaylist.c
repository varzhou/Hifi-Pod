/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of XMMSClientPlaylist.xs. Do not edit this file, edit XMMSClientPlaylist.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
#include "perl_xmmsclient.h"

#line 13 "../src/clients/lib/perl/XMMSClientPlaylist.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

#line 56 "../src/clients/lib/perl/XMMSClientPlaylist.c"

XS(XS_Audio__XMMSClient__Playlist_list_entries); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_list_entries)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_list_entries(p->conn, p->name);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_create); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_create)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_create(p->conn, p->name);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_current_pos); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_current_pos)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_current_pos(p->conn, p->name);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_shuffle); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_shuffle)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_shuffle(p->conn, p->name);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_sort); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_sort)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "p, properties");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsv_t *	properties = (xmmsv_t *)perl_xmmsclient_pack_stringlist (ST(1));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_sort(p->conn, p->name, properties);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
#line 136 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		xmmsv_unref (properties);
#line 171 "../src/clients/lib/perl/XMMSClientPlaylist.c"
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_clear); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_clear)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_clear(p->conn, p->name);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_insert_id); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_insert_id)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "p, pos, id");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	int	pos = (int)SvIV(ST(1));
	unsigned int	id = (unsigned int)SvUV(ST(2));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_insert_id(p->conn, p->name, pos, id);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_insert_args); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_insert_args)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 3)
       croak_xs_usage(cv,  "p, pos, url, ...");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	int	pos = (int)SvIV(ST(1));
	const char *	url = (const char *)SvPV_nolen(ST(2));
#line 206 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		int i, nargs;
		const char **args = NULL;
#line 242 "../src/clients/lib/perl/XMMSClientPlaylist.c"
	xmmsc_result_t *	RETVAL;
#line 209 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		nargs = items - 2;
		args = (const char **)malloc (sizeof (char *) * nargs);

		for (i = 0; i < nargs; i++) {
			args[i] = SvPV_nolen (ST (i+2));
		}
#line 251 "../src/clients/lib/perl/XMMSClientPlaylist.c"

	RETVAL = xmmsc_playlist_insert_args(p->conn, p->name, pos, url, nargs, args);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
#line 218 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		free (args);
#line 259 "../src/clients/lib/perl/XMMSClientPlaylist.c"
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_insert_url); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_insert_url)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "p, pos, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	int	pos = (int)SvIV(ST(1));
	const char *	url = (const char *)SvPV_nolen(ST(2));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_insert_url(p->conn, p->name, pos, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_insert_encoded); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_insert_encoded)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "p, pos, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	int	pos = (int)SvIV(ST(1));
	const char *	url = (const char *)SvPV_nolen(ST(2));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_insert_encoded(p->conn, p->name, pos, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_insert_collection); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_insert_collection)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 4)
       croak_xs_usage(cv,  "p, pos, collection, order");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	int	pos = (int)SvIV(ST(1));
	xmmsv_coll_t *	collection = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(2), "Audio::XMMSClient::Collection");
	xmmsv_t *	order = (xmmsv_t *)perl_xmmsclient_pack_stringlist (ST(3));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_insert_collection(p->conn, p->name, pos, collection, order);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
#line 294 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		free (order);
#line 338 "../src/clients/lib/perl/XMMSClientPlaylist.c"
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_add_id); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_add_id)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "p, id");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	unsigned int	id = (unsigned int)SvUV(ST(1));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_add_id(p->conn, p->name, id);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_add_args); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_add_args)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "p, url, ...");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	const char *	url = (const char *)SvPV_nolen(ST(1));
#line 340 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		int i, nargs;
		const char **args = NULL;
#line 384 "../src/clients/lib/perl/XMMSClientPlaylist.c"
	xmmsc_result_t *	RETVAL;
#line 343 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		nargs = items - 1;
		args = (const char **)malloc (sizeof (char *) * nargs);

		for (i = 0; i < nargs; i++) {
			args[i] = SvPV_nolen (ST (i+1));
		}
#line 393 "../src/clients/lib/perl/XMMSClientPlaylist.c"

	RETVAL = xmmsc_playlist_add_args(p->conn, p->name, url, nargs, args);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
#line 352 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		free (args);
#line 401 "../src/clients/lib/perl/XMMSClientPlaylist.c"
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_add_url); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_add_url)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "p, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	const char *	url = (const char *)SvPV_nolen(ST(1));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_add_url(p->conn, p->name, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_add_encoded); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_add_encoded)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "p, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	const char *	url = (const char *)SvPV_nolen(ST(1));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_add_encoded(p->conn, p->name, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_add_collection); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_add_collection)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "p, collection, order");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsv_coll_t *	collection = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(1), "Audio::XMMSClient::Collection");
	xmmsv_t *	order = (xmmsv_t *)perl_xmmsclient_pack_stringlist (ST(2));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_add_collection(p->conn, p->name, collection, order);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
#line 423 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		free (order);
#line 477 "../src/clients/lib/perl/XMMSClientPlaylist.c"
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_move_entry); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_move_entry)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "p, cur_pos, new_pos");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	uint32_t	cur_pos = (uint32_t)SvUV(ST(1));
	uint32_t	new_pos = (uint32_t)SvUV(ST(2));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_move_entry(p->conn, p->name, cur_pos, new_pos);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_remove_entry); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_remove_entry)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "p, pos");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	unsigned int	pos = (unsigned int)SvUV(ST(1));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_remove_entry(p->conn, p->name, pos);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_remove); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_remove)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_remove(p->conn, p->name);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_load); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_load)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_load(p->conn, p->name);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_radd); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_radd)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "p, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	const char *	url = (const char *)SvPV_nolen(ST(1));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_radd(p->conn, p->name, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_radd_encoded); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_radd_encoded)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "p, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	const char *	url = (const char *)SvPV_nolen(ST(1));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_radd_encoded(p->conn, p->name, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_rinsert); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_rinsert)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "p, pos, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	int	pos = (int)SvIV(ST(1));
	const char *	url = (const char *)SvPV_nolen(ST(2));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_rinsert(p->conn, p->name, pos, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_rinsert_encoded); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_rinsert_encoded)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "p, pos, url");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
	int	pos = (int)SvIV(ST(1));
	const char *	url = (const char *)SvPV_nolen(ST(2));
	xmmsc_result_t *	RETVAL;

	RETVAL = xmmsc_playlist_rinsert_encoded(p->conn, p->name, pos, url);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Result");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Playlist_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Playlist_DESTROY)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "p");
    {
	perl_xmmsclient_playlist_t *	p = (perl_xmmsclient_playlist_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Playlist");
#line 616 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
		perl_xmmsclient_playlist_destroy (p);
#line 690 "../src/clients/lib/perl/XMMSClientPlaylist.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Audio__XMMSClient__Playlist); /* prototype to pass -Wmissing-prototypes */
XS(boot_Audio__XMMSClient__Playlist)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    const char* file = __FILE__;

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        newXS("Audio::XMMSClient::Playlist::list_entries", XS_Audio__XMMSClient__Playlist_list_entries, file);
        newXS("Audio::XMMSClient::Playlist::create", XS_Audio__XMMSClient__Playlist_create, file);
        newXS("Audio::XMMSClient::Playlist::current_pos", XS_Audio__XMMSClient__Playlist_current_pos, file);
        newXS("Audio::XMMSClient::Playlist::shuffle", XS_Audio__XMMSClient__Playlist_shuffle, file);
        newXS("Audio::XMMSClient::Playlist::sort", XS_Audio__XMMSClient__Playlist_sort, file);
        newXS("Audio::XMMSClient::Playlist::clear", XS_Audio__XMMSClient__Playlist_clear, file);
        newXS("Audio::XMMSClient::Playlist::insert_id", XS_Audio__XMMSClient__Playlist_insert_id, file);
        newXS("Audio::XMMSClient::Playlist::insert_args", XS_Audio__XMMSClient__Playlist_insert_args, file);
        newXS("Audio::XMMSClient::Playlist::insert_url", XS_Audio__XMMSClient__Playlist_insert_url, file);
        newXS("Audio::XMMSClient::Playlist::insert_encoded", XS_Audio__XMMSClient__Playlist_insert_encoded, file);
        newXS("Audio::XMMSClient::Playlist::insert_collection", XS_Audio__XMMSClient__Playlist_insert_collection, file);
        newXS("Audio::XMMSClient::Playlist::add_id", XS_Audio__XMMSClient__Playlist_add_id, file);
        newXS("Audio::XMMSClient::Playlist::add_args", XS_Audio__XMMSClient__Playlist_add_args, file);
        newXS("Audio::XMMSClient::Playlist::add_url", XS_Audio__XMMSClient__Playlist_add_url, file);
        newXS("Audio::XMMSClient::Playlist::add_encoded", XS_Audio__XMMSClient__Playlist_add_encoded, file);
        newXS("Audio::XMMSClient::Playlist::add_collection", XS_Audio__XMMSClient__Playlist_add_collection, file);
        newXS("Audio::XMMSClient::Playlist::move_entry", XS_Audio__XMMSClient__Playlist_move_entry, file);
        newXS("Audio::XMMSClient::Playlist::remove_entry", XS_Audio__XMMSClient__Playlist_remove_entry, file);
        newXS("Audio::XMMSClient::Playlist::remove", XS_Audio__XMMSClient__Playlist_remove, file);
        newXS("Audio::XMMSClient::Playlist::load", XS_Audio__XMMSClient__Playlist_load, file);
        newXS("Audio::XMMSClient::Playlist::radd", XS_Audio__XMMSClient__Playlist_radd, file);
        newXS("Audio::XMMSClient::Playlist::radd_encoded", XS_Audio__XMMSClient__Playlist_radd_encoded, file);
        newXS("Audio::XMMSClient::Playlist::rinsert", XS_Audio__XMMSClient__Playlist_rinsert, file);
        newXS("Audio::XMMSClient::Playlist::rinsert_encoded", XS_Audio__XMMSClient__Playlist_rinsert_encoded, file);
        newXS("Audio::XMMSClient::Playlist::DESTROY", XS_Audio__XMMSClient__Playlist_DESTROY, file);

    /* Initialisation Section */

#line 637 "../src/clients/lib/perl/XMMSClientPlaylist.xs"
	PERL_UNUSED_VAR (items);

#line 743 "../src/clients/lib/perl/XMMSClientPlaylist.c"

    /* End of Initialisation Section */

    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}
