/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of XMMSClientCollection.xs. Do not edit this file, edit XMMSClientCollection.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "../src/clients/lib/perl/XMMSClientCollection.xs"
#include "perl_xmmsclient.h"

#line 13 "../src/clients/lib/perl/XMMSClientCollection.c"
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

#line 56 "../src/clients/lib/perl/XMMSClientCollection.c"

XS(XS_Audio__XMMSClient__Collection_new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "class, type, ...");
    {
	xmmsv_coll_type_t	type;
#line 44 "../src/clients/lib/perl/XMMSClientCollection.xs"
		int i, nargs;
		HV *args;
		HE *iter;
#line 74 "../src/clients/lib/perl/XMMSClientCollection.c"
	xmmsv_coll_t *	RETVAL;

	{
		char *coll_type = SvPV_nolen (ST(1));

		if (strcmp (coll_type, "reference") == 0) {
			type = XMMS_COLLECTION_TYPE_REFERENCE;
		}
		else if (strcmp (coll_type, "union") == 0) {
			type = XMMS_COLLECTION_TYPE_UNION;
		}
		else if (strcmp (coll_type, "intersection") == 0) {
			type = XMMS_COLLECTION_TYPE_INTERSECTION;
		}
		else if (strcmp (coll_type, "complement") == 0) {
			type = XMMS_COLLECTION_TYPE_COMPLEMENT;
		}
		else if (strcmp (coll_type, "has") == 0) {
			type = XMMS_COLLECTION_TYPE_HAS;
		}
		else if (strcmp (coll_type, "equals") == 0) {
			type = XMMS_COLLECTION_TYPE_EQUALS;
		}
		else if (strcmp (coll_type, "notequal") == 0) {
			type = XMMS_COLLECTION_TYPE_NOTEQUAL;
		}
		else if (strcmp (coll_type, "match") == 0) {
			type = XMMS_COLLECTION_TYPE_MATCH;
		}
		else if (strcmp (coll_type, "smaller") == 0) {
			type = XMMS_COLLECTION_TYPE_SMALLER;
		}
		else if (strcmp (coll_type, "smallereq") == 0) {
			type = XMMS_COLLECTION_TYPE_SMALLEREQ;
		}
		else if (strcmp (coll_type, "greater") == 0) {
			type = XMMS_COLLECTION_TYPE_GREATER;
		}
		else if (strcmp (coll_type, "greatereq") == 0) {
			type = XMMS_COLLECTION_TYPE_GREATEREQ;
		}
		else if (strcmp (coll_type, "order") == 0) {
			type = XMMS_COLLECTION_TYPE_ORDER;
		}
		else if (strcmp (coll_type, "limit") == 0) {
			type = XMMS_COLLECTION_TYPE_LIMIT;
		}
		else if (strcmp (coll_type, "mediaset") == 0) {
			type = XMMS_COLLECTION_TYPE_MEDIASET;
		}
		else if (strcmp (coll_type, "idlist") == 0) {
			type = XMMS_COLLECTION_TYPE_IDLIST;
		}
		else {
			croak ("unknown XMMSV_COLL_TYPE_T: %s", coll_type);
		}
	};
#line 48 "../src/clients/lib/perl/XMMSClientCollection.xs"
		RETVAL = xmmsv_coll_new (type);

		nargs = items - 2;
		if (nargs == 1) {
			if (!SvOK (ST (2)) || !SvROK (ST (2)) || !(SvTYPE (SvRV (ST (2))) == SVt_PVHV))
				croak ("expected hash reference or hash");

			args = (HV *)SvRV (ST (2));

			hv_iterinit (args);
			while ((iter = hv_iternext (args))) {
				xmmsv_coll_attribute_set (RETVAL, HePV (iter, PL_na), SvPV_nolen (HeVAL (iter)));
			}
		}
		else {
			if (nargs % 2 != 0)
				croak ("expected even number of attributes/values");

			for (i = 2; i <= nargs; i += 2) {
				xmmsv_coll_attribute_set (RETVAL, SvPV_nolen (ST (i)), SvPV_nolen (ST (i+1)));
			}
		}
#line 155 "../src/clients/lib/perl/XMMSClientCollection.c"
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Collection");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_parse); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_parse)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, pattern");
    {
#line 92 "../src/clients/lib/perl/XMMSClientCollection.xs"
		int ret;
#line 177 "../src/clients/lib/perl/XMMSClientCollection.c"
	xmmsv_coll_t *	RETVAL;
	const char *	pattern = (const char *)SvPV_nolen(ST(1));
#line 94 "../src/clients/lib/perl/XMMSClientCollection.xs"
		ret = xmmsv_coll_parse (pattern, &RETVAL);
#line 182 "../src/clients/lib/perl/XMMSClientCollection.c"
#line 96 "../src/clients/lib/perl/XMMSClientCollection.xs"
		if (ret == 0)
			XSRETURN_UNDEF;
#line 186 "../src/clients/lib/perl/XMMSClientCollection.c"
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Collection");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_DESTROY)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "coll");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
#line 105 "../src/clients/lib/perl/XMMSClientCollection.xs"
		xmmsv_coll_unref (coll);
#line 209 "../src/clients/lib/perl/XMMSClientCollection.c"
    }
    XSRETURN_EMPTY;
}


XS(XS_Audio__XMMSClient__Collection_set_idlist); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_set_idlist)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 1)
       croak_xs_usage(cv,  "coll, ...");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
#line 128 "../src/clients/lib/perl/XMMSClientCollection.xs"
		int i;
		int *ids;
#line 230 "../src/clients/lib/perl/XMMSClientCollection.c"
#line 131 "../src/clients/lib/perl/XMMSClientCollection.xs"
		ids = (int *)malloc (sizeof (int) * items);

		for (i = 0; i < items - 1; i++) {
			ids[i] = SvUV (ST (i + 1));
			if (ids[i] == 0) {
				free (ids);
				croak("0 is an invalid mlib id");
			}
		}

		ids[items - 1] = 0;
#line 243 "../src/clients/lib/perl/XMMSClientCollection.c"

	xmmsv_coll_set_idlist(coll, ids);
#line 145 "../src/clients/lib/perl/XMMSClientCollection.xs"
		free (ids);
#line 248 "../src/clients/lib/perl/XMMSClientCollection.c"
    }
    XSRETURN_EMPTY;
}


XS(XS_Audio__XMMSClient__Collection_add_operand); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_add_operand)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "coll, op");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	xmmsv_coll_t *	op = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(1), "Audio::XMMSClient::Collection");

	xmmsv_coll_add_operand(coll, op);
    }
    XSRETURN_EMPTY;
}


XS(XS_Audio__XMMSClient__Collection_remove_operand); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_remove_operand)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "coll, op");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	xmmsv_coll_t *	op = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(1), "Audio::XMMSClient::Collection");

	xmmsv_coll_remove_operand(coll, op);
    }
    XSRETURN_EMPTY;
}


XS(XS_Audio__XMMSClient__Collection_idlist_append); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_idlist_append)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "coll, id");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	unsigned int	id = (unsigned int)SvUV(ST(1));
	int	RETVAL;
	dXSTARG;
#line 210 "../src/clients/lib/perl/XMMSClientCollection.xs"
		if (id == 0) {
			croak ("0 is an invalid mlib id");
		}
#line 313 "../src/clients/lib/perl/XMMSClientCollection.c"

	RETVAL = xmmsv_coll_idlist_append(coll, id);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_idlist_insert); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_idlist_insert)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "coll, index, id");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	unsigned int	index = (unsigned int)SvUV(ST(1));
	unsigned int	id = (unsigned int)SvUV(ST(2));
	int	RETVAL;
	dXSTARG;
#line 236 "../src/clients/lib/perl/XMMSClientCollection.xs"
		if (index > xmmsv_coll_idlist_get_size (coll)) {
			croak ("inserting id after end of idlist");
		}

		if (id == 0) {
			croak ("0 is an invalid mlib id");
		}
#line 346 "../src/clients/lib/perl/XMMSClientCollection.c"

	RETVAL = xmmsv_coll_idlist_insert(coll, index, id);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_idlist_move); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_idlist_move)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "coll, from, to");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	unsigned int	from = (unsigned int)SvUV(ST(1));
	unsigned int	to = (unsigned int)SvUV(ST(2));
#line 266 "../src/clients/lib/perl/XMMSClientCollection.xs"
		size_t idlist_len;
#line 371 "../src/clients/lib/perl/XMMSClientCollection.c"
	int	RETVAL;
	dXSTARG;
#line 268 "../src/clients/lib/perl/XMMSClientCollection.xs"
		idlist_len = xmmsv_coll_idlist_get_size (coll);

		if (from > idlist_len) {
			croak ("trying to move id from after the idlists end");
		}

		if (to >= idlist_len) {
			croak ("trying to move id to after the idlists end");
		}
#line 384 "../src/clients/lib/perl/XMMSClientCollection.c"

	RETVAL = xmmsv_coll_idlist_move(coll, from, to);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_idlist_clear); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_idlist_clear)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "coll");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	int	RETVAL;
	dXSTARG;

	RETVAL = xmmsv_coll_idlist_clear(coll);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_idlist_get_index); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_idlist_get_index)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "coll, index");
    {
	int	RETVAL;
	dXSTARG;
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	unsigned int	index = (unsigned int)SvUV(ST(1));
	int32_t	val;
#line 317 "../src/clients/lib/perl/XMMSClientCollection.xs"
		PERL_UNUSED_VAR (targ);

		if (index > xmmsv_coll_idlist_get_size (coll)) {
			croak ("trying to get an id from behind the idlists end");
		}
#line 437 "../src/clients/lib/perl/XMMSClientCollection.c"

	RETVAL = xmmsv_coll_idlist_get_index(coll, index, &val);
#line 323 "../src/clients/lib/perl/XMMSClientCollection.xs"
		if (RETVAL == 0)
			XSRETURN_UNDEF;
#line 443 "../src/clients/lib/perl/XMMSClientCollection.c"
	XSprePUSH;	EXTEND(SP,1);
	PUSHs(sv_newmortal());
	sv_setiv(ST(0), (IV)val);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_idlist_set_index); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_idlist_set_index)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "coll, index, val");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	unsigned int	index = (unsigned int)SvUV(ST(1));
	int32_t	val = (int32_t)SvIV(ST(2));
#line 348 "../src/clients/lib/perl/XMMSClientCollection.xs"
		size_t idlist_len;
#line 468 "../src/clients/lib/perl/XMMSClientCollection.c"
	int	RETVAL;
	dXSTARG;
#line 350 "../src/clients/lib/perl/XMMSClientCollection.xs"
		idlist_len = xmmsv_coll_idlist_get_size (coll);
		if (idlist_len == 0 || index > idlist_len - 1) {
			croak ("trying to set an id after the end of the idlist");
		}
#line 476 "../src/clients/lib/perl/XMMSClientCollection.c"

	RETVAL = xmmsv_coll_idlist_set_index(coll, index, val);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_idlist_get_size); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_idlist_get_size)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "coll");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	size_t	RETVAL;
	dXSTARG;

	RETVAL = xmmsv_coll_idlist_get_size(coll);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_get_type); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_get_type)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "coll");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	xmmsv_coll_type_t	RETVAL;

	RETVAL = xmmsv_coll_get_type(coll);
	ST(0) = sv_newmortal();
	{
		ST(0) = newSVpv ("", 0);
		if (RETVAL == XMMS_COLLECTION_TYPE_REFERENCE) {
			sv_setpv (ST(0), "reference");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_UNION) {
			sv_setpv (ST(0), "union");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_INTERSECTION) {
			sv_setpv (ST(0), "intersection");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_COMPLEMENT) {
			sv_setpv (ST(0), "complement");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_HAS) {
			sv_setpv (ST(0), "has");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_EQUALS) {
			sv_setpv (ST(0), "equals");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_NOTEQUAL) {
			sv_setpv (ST(0), "notequal");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_MATCH) {
			sv_setpv (ST(0), "match");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_SMALLER) {
			sv_setpv (ST(0), "smaller");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_SMALLEREQ) {
			sv_setpv (ST(0), "smallereq");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_GREATER) {
			sv_setpv (ST(0), "greater");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_GREATEREQ) {
			sv_setpv (ST(0), "greatereq");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_ORDER) {
			sv_setpv (ST(0), "order");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_LIMIT) {
			sv_setpv (ST(0), "limit");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_MEDIASET) {
			sv_setpv (ST(0), "mediaset");
		}
		else if (RETVAL == XMMS_COLLECTION_TYPE_IDLIST) {
			sv_setpv (ST(0), "idlist");
		}
		else {
			croak ("unknown XMMSV_COLL_TYPE_T");
		}
	}

    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_get_idlist); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_get_idlist)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "coll");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
#line 419 "../src/clients/lib/perl/XMMSClientCollection.xs"
		xmmsv_list_iter_t *it;
		int32_t entry;
#line 600 "../src/clients/lib/perl/XMMSClientCollection.c"
#line 422 "../src/clients/lib/perl/XMMSClientCollection.xs"
		if (!xmmsv_get_list_iter (xmmsv_coll_idlist_get (coll), &it))
			XSRETURN_UNDEF;

		EXTEND (sp, xmmsv_coll_idlist_get_size (coll));

		for (xmmsv_list_iter_first (it);
		     xmmsv_list_iter_valid (it);
		     xmmsv_list_iter_next (it)) {

			xmmsv_list_iter_entry_int (it, &entry);
			PUSHs (sv_2mortal (newSVuv (entry)));
		}
		xmmsv_list_iter_explicit_destroy (it);
#line 615 "../src/clients/lib/perl/XMMSClientCollection.c"
	PUTBACK;
	return;
    }
}


XS(XS_Audio__XMMSClient__Collection_operands); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_operands)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "coll");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
#line 458 "../src/clients/lib/perl/XMMSClientCollection.xs"
		xmmsv_t *operands_list;
		xmmsv_list_iter_t *it;
		xmmsv_t *value;
		xmmsv_coll_t *op;
#line 642 "../src/clients/lib/perl/XMMSClientCollection.c"
#line 463 "../src/clients/lib/perl/XMMSClientCollection.xs"
		PERL_UNUSED_VAR (ix);

		operands_list = xmmsv_coll_operands_get (coll);

		for (xmmsv_get_list_iter (operands_list, &it);
		     xmmsv_list_iter_entry (it, &value);
		     xmmsv_list_iter_next (it)) {
			xmmsv_get_coll (value, &op);
			xmmsv_coll_ref (op);
			XPUSHs (sv_2mortal (perl_xmmsclient_new_sv_from_ptr (op, "Audio::XMMSClient::Collection")));
		}

		xmmsv_list_iter_explicit_destroy (it);
#line 657 "../src/clients/lib/perl/XMMSClientCollection.c"
	PUTBACK;
	return;
    }
}


XS(XS_Audio__XMMSClient__Collection_attribute_set); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_attribute_set)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "coll, key, value");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	const char *	key = (const char *)SvPV_nolen(ST(1));
	const char *	value = (const char *)SvPV_nolen(ST(2));

	xmmsv_coll_attribute_set(coll, key, value);
    }
    XSRETURN_EMPTY;
}


XS(XS_Audio__XMMSClient__Collection_attribute_remove); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_attribute_remove)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "coll, key");
    {
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	const char *	key = (const char *)SvPV_nolen(ST(1));
	int	RETVAL;
	dXSTARG;

	RETVAL = xmmsv_coll_attribute_remove(coll, key);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_attribute_get); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_attribute_get)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "coll, key");
    {
	int	RETVAL;
	dXSTARG;
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
	const char *	key = (const char *)SvPV_nolen(ST(1));
	const char *	val;
#line 540 "../src/clients/lib/perl/XMMSClientCollection.xs"
		PERL_UNUSED_VAR (targ);
#line 726 "../src/clients/lib/perl/XMMSClientCollection.c"

	RETVAL = xmmsv_coll_attribute_get(coll, key, &val);
#line 542 "../src/clients/lib/perl/XMMSClientCollection.xs"
		if (RETVAL == 0)
			XSRETURN_UNDEF;
#line 732 "../src/clients/lib/perl/XMMSClientCollection.c"
	XSprePUSH;	EXTEND(SP,1);
	PUSHs(sv_newmortal());
	sv_setpv((SV*)ST(0), val);
    }
    XSRETURN(1);
}


XS(XS_Audio__XMMSClient__Collection_attribute_list); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_attribute_list)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "coll");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 564 "../src/clients/lib/perl/XMMSClientCollection.xs"
		xmmsv_dict_iter_t *it;
		const char *key;
		const char *value;
#line 758 "../src/clients/lib/perl/XMMSClientCollection.c"
	xmmsv_coll_t *	coll = (xmmsv_coll_t *)perl_xmmsclient_get_ptr_from_sv (ST(0), "Audio::XMMSClient::Collection");
#line 568 "../src/clients/lib/perl/XMMSClientCollection.xs"
		xmmsv_get_dict_iter (xmmsv_coll_attributes_get (coll), &it);

		for (xmmsv_dict_iter_first (it);
		     xmmsv_dict_iter_valid (it);
		     xmmsv_dict_iter_next (it)) {

			xmmsv_dict_iter_pair_string (it, &key, &value);

			EXTEND (sp, 2);
			mPUSHp (key, strlen (key));
			mPUSHp (value, strlen (value));
		}

		xmmsv_dict_iter_explicit_destroy (it);
#line 775 "../src/clients/lib/perl/XMMSClientCollection.c"
	PUTBACK;
	return;
    }
}


XS(XS_Audio__XMMSClient__Collection_universe); /* prototype to pass -Wmissing-prototypes */
XS(XS_Audio__XMMSClient__Collection_universe)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 0 || items > 1)
       croak_xs_usage(cv,  "class=\"optional\"");
    {
	xmmsv_coll_t *	RETVAL;

	RETVAL = xmmsv_coll_universe(/* void */);
	ST(0) = perl_xmmsclient_new_sv_from_ptr (RETVAL, "Audio::XMMSClient::Collection");

	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Audio__XMMSClient__Collection); /* prototype to pass -Wmissing-prototypes */
XS(boot_Audio__XMMSClient__Collection)
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

    {
        CV * cv ;

        newXS("Audio::XMMSClient::Collection::new", XS_Audio__XMMSClient__Collection_new, file);
        newXS("Audio::XMMSClient::Collection::parse", XS_Audio__XMMSClient__Collection_parse, file);
        newXS("Audio::XMMSClient::Collection::DESTROY", XS_Audio__XMMSClient__Collection_DESTROY, file);
        newXS("Audio::XMMSClient::Collection::set_idlist", XS_Audio__XMMSClient__Collection_set_idlist, file);
        newXS("Audio::XMMSClient::Collection::add_operand", XS_Audio__XMMSClient__Collection_add_operand, file);
        newXS("Audio::XMMSClient::Collection::remove_operand", XS_Audio__XMMSClient__Collection_remove_operand, file);
        newXS("Audio::XMMSClient::Collection::idlist_append", XS_Audio__XMMSClient__Collection_idlist_append, file);
        newXS("Audio::XMMSClient::Collection::idlist_insert", XS_Audio__XMMSClient__Collection_idlist_insert, file);
        newXS("Audio::XMMSClient::Collection::idlist_move", XS_Audio__XMMSClient__Collection_idlist_move, file);
        newXS("Audio::XMMSClient::Collection::idlist_clear", XS_Audio__XMMSClient__Collection_idlist_clear, file);
        newXS("Audio::XMMSClient::Collection::idlist_get_index", XS_Audio__XMMSClient__Collection_idlist_get_index, file);
        newXS("Audio::XMMSClient::Collection::idlist_set_index", XS_Audio__XMMSClient__Collection_idlist_set_index, file);
        newXS("Audio::XMMSClient::Collection::idlist_get_size", XS_Audio__XMMSClient__Collection_idlist_get_size, file);
        newXS("Audio::XMMSClient::Collection::get_type", XS_Audio__XMMSClient__Collection_get_type, file);
        newXS("Audio::XMMSClient::Collection::get_idlist", XS_Audio__XMMSClient__Collection_get_idlist, file);
        cv = newXS("Audio::XMMSClient::Collection::operand_list", XS_Audio__XMMSClient__Collection_operands, file);
        XSANY.any_i32 = 1 ;
        cv = newXS("Audio::XMMSClient::Collection::operands", XS_Audio__XMMSClient__Collection_operands, file);
        XSANY.any_i32 = 0 ;
        newXS("Audio::XMMSClient::Collection::attribute_set", XS_Audio__XMMSClient__Collection_attribute_set, file);
        newXS("Audio::XMMSClient::Collection::attribute_remove", XS_Audio__XMMSClient__Collection_attribute_remove, file);
        newXS("Audio::XMMSClient::Collection::attribute_get", XS_Audio__XMMSClient__Collection_attribute_get, file);
        newXS("Audio::XMMSClient::Collection::attribute_list", XS_Audio__XMMSClient__Collection_attribute_list, file);
        newXS("Audio::XMMSClient::Collection::universe", XS_Audio__XMMSClient__Collection_universe, file);
    }

    /* Initialisation Section */

#line 624 "../src/clients/lib/perl/XMMSClientCollection.xs"
	PERL_UNUSED_VAR (items);

#line 854 "../src/clients/lib/perl/XMMSClientCollection.c"

    /* End of Initialisation Section */

    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}
