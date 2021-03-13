all: WINDOW

WINDOW:
	@echo Building...
	@go build -ldflags "-s -w"
	@echo Done.

NOWINDOW:
	@echo Building...
	@go build -ldflags "-s -w -H=windowsgui"
	@echo Done.
