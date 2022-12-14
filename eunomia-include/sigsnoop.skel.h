/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED BY BPFTOOL! */
#ifndef __SIGSNOOP_BPF_SKEL_H__
#define __SIGSNOOP_BPF_SKEL_H__

extern int errno;
#include <stdlib.h>

struct bpf_object_skeleton;
struct bpf_object;
struct bpf_map;
struct bpf_program;
struct bpf_object_open_opts;
struct bpf_link;

struct sigsnoop_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *events;
		struct bpf_map *values;
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *kill_entry;
		struct bpf_program *kill_exit;
		struct bpf_program *tkill_entry;
		struct bpf_program *tkill_exit;
		struct bpf_program *tgkill_entry;
		struct bpf_program *tgkill_exit;
		struct bpf_program *sig_trace;
	} progs;
	struct {
		struct bpf_link *kill_entry;
		struct bpf_link *kill_exit;
		struct bpf_link *tkill_entry;
		struct bpf_link *tkill_exit;
		struct bpf_link *tgkill_entry;
		struct bpf_link *tgkill_exit;
		struct bpf_link *sig_trace;
	} links;
	struct sigsnoop_bpf__rodata {
		int filtered_pid;
		int target_signal;
		bool failed_only;
	} *rodata;

#ifdef __cplusplus
	static inline struct sigsnoop_bpf *open(const struct bpf_object_open_opts *opts = nullptr);
	static inline struct sigsnoop_bpf *open_and_load();
	static inline int load(struct sigsnoop_bpf *skel);
	static inline int attach(struct sigsnoop_bpf *skel);
	static inline void detach(struct sigsnoop_bpf *skel);
	static inline void destroy(struct sigsnoop_bpf *skel);
	static inline const void *elf_bytes(size_t *sz);
#endif /* __cplusplus */
};

static void
sigsnoop_bpf__destroy(struct sigsnoop_bpf *obj)
{

}

static inline int
sigsnoop_bpf__create_skeleton(struct sigsnoop_bpf *obj);

static inline struct sigsnoop_bpf *
sigsnoop_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct sigsnoop_bpf *obj;
	int err;

	obj = (struct sigsnoop_bpf *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}
	return obj;
}

static inline struct sigsnoop_bpf *
sigsnoop_bpf__open(void)
{
    return sigsnoop_bpf__open_opts(NULL);
}

static inline int
sigsnoop_bpf__load(struct sigsnoop_bpf *obj)
{
	return 0;
}

static inline struct sigsnoop_bpf *
sigsnoop_bpf__open_and_load(void)
{
	return NULL;
}

static inline int
sigsnoop_bpf__attach(struct sigsnoop_bpf *obj)
{
	return 0;
}

static inline void
sigsnoop_bpf__detach(struct sigsnoop_bpf *obj)
{
}

static inline const void *sigsnoop_bpf__elf_bytes(size_t *sz);

static inline int
sigsnoop_bpf__create_skeleton(struct sigsnoop_bpf *obj)
{
	return 0;
}

#ifdef __cplusplus
struct sigsnoop_bpf *sigsnoop_bpf::open(const struct bpf_object_open_opts *opts) { return sigsnoop_bpf__open_opts(opts); }
struct sigsnoop_bpf *sigsnoop_bpf::open_and_load() { return sigsnoop_bpf__open_and_load(); }
int sigsnoop_bpf::load(struct sigsnoop_bpf *skel) { return sigsnoop_bpf__load(skel); }
int sigsnoop_bpf::attach(struct sigsnoop_bpf *skel) { return sigsnoop_bpf__attach(skel); }
void sigsnoop_bpf::detach(struct sigsnoop_bpf *skel) { sigsnoop_bpf__detach(skel); }
void sigsnoop_bpf::destroy(struct sigsnoop_bpf *skel) { sigsnoop_bpf__destroy(skel); }
const void *sigsnoop_bpf::elf_bytes(size_t *sz) { return sigsnoop_bpf__elf_bytes(sz); }
#endif /* __cplusplus */

__attribute__((unused)) static void
sigsnoop_bpf__assert(struct sigsnoop_bpf *s __attribute__((unused)))
{
#ifdef __cplusplus
#define _Static_assert static_assert
#endif
	_Static_assert(sizeof(s->rodata->filtered_pid) == 4, "unexpected size of 'filtered_pid'");
	_Static_assert(sizeof(s->rodata->target_signal) == 4, "unexpected size of 'target_signal'");
	_Static_assert(sizeof(s->rodata->failed_only) == 1, "unexpected size of 'failed_only'");
#ifdef __cplusplus
#undef _Static_assert
#endif
}

struct perf_buffer;
void perf_buffer__free(struct perf_buffer *pb) {
}
int perf_buffer__poll(struct perf_buffer *pb, int timeout_ms) {
	return start_bpf_program(program_data);
}
int bpf_program__set_autoload(struct bpf_program *prog, bool autoload) {
    return 0;
}
char* strerror(int errnum) {
    return "error";
}
int bpf_map__fd(const struct bpf_map *map) {
    return 0;
}
typedef void (*perf_buffer_sample_fn)(void *ctx, int cpu,
				      void *data, unsigned int size);
typedef void (*perf_buffer_lost_fn)(void *ctx, int cpu, unsigned long long cnt);
struct perf_buffer;

perf_buffer_sample_fn global_cb;
struct perf_buffer_opts;

struct perf_buffer *
perf_buffer__new(int map_fd, size_t page_cnt,
		 perf_buffer_sample_fn sample_cb, perf_buffer_lost_fn lost_cb, void *ctx,
		 const struct perf_buffer_opts *opts) {
    global_cb = sample_cb;
    return (void*)1;
         }

int process_event(int ctx, char *e, int str_len)
{
    struct event eve = {0};
    cJSON *json = cJSON_Parse(e);
	eve.sig = cJSON_GetObjectItem(json, "sig")->valueint;
    eve.pid = cJSON_GetObjectItem(json, "pid")->valueint;
    strcpy(eve.comm, cJSON_GetObjectItem(json, "comm")->valuestring);
    eve.tpid = cJSON_GetObjectItem(json, "tpid")->valueint;
    eve.ret = cJSON_GetObjectItem(json, "ret")->valueint;
	global_cb((void*)ctx, 0, &eve, str_len);
	return 0;
}

extern const char argp_program_doc[];

void argp_state_help(const struct argp_state *__state, int flag) {
    printf("%s", argp_program_doc);
    exit(0);
}

#endif /* __SIGSNOOP_BPF_SKEL_H__ */
