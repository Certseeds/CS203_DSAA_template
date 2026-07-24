#!/usr/bin/env bash
set -euox pipefail
main() {
    local SOURCE="ghcr.io"
    local GH_USERNAME="certseeds"
    local IMAGE_NAME="develop"
    local RUNTIME_NAME="algorithm-cpp-dev"
    local dotfiles="${DOTFILES_DIR}"
    # 请确认环境内存在 USERNAME, DOTFILES_DIR 这两个变量
    # 请确认环境内指定路径上有 cc 的配置文件
    podman run \
        --userns=keep-id:uid=1001  \
        -dit \
        -e HTTP_PROXY="" \
        -e HTTPS_PROXY="" \
        -e http_proxy="" \
        -e https_proxy="" \
        --name "${RUNTIME_NAME}" \
        -v $(pwd):/home/${USERNAME}/repo/algorithm-template \
        -v algorithm-cpp-venv:/home/${USERNAME}/repo/algorithm-template/.venv \
        -v algorithm-cpp-node-modules:/home/${USERNAME}/repo/algorithm-template/node_modules \
        -v algorithm-cpp-pnpm:/home/${USERNAME}/repo/algorithm-template/.pnpm-store \
        -v algorithm-cpp-cmake-build-debug:/home/${USERNAME}/repo/algorithm-template/cmake-build-debug \
        -v algorithm-cpp-cmake-build-release:/home/${USERNAME}/repo/algorithm-template/cmake-build-release \
        -v algorithm-cpp-claude:/home/${USERNAME}/.claude/ \
        "${SOURCE}/${GH_USERNAME}/${IMAGE_NAME}:latest"
    podman cp "${dotfiles}"/lang/agents/cc.json "${RUNTIME_NAME}":/home/${USERNAME}/.claude/settings.json

    # run pnpm setup
    # vim the claude code settings.json, to enable allow-dangerous tasks
}
main
